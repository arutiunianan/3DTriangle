#include "octree.h"

bool BoundingBox::contains_triangle(Triangle_t triangle) {
    return contains_point(triangle.get_a()) &&
           contains_point(triangle.get_b()) &&
           contains_point(triangle.get_c());
}
bool BoundingBox::contains_point(Point_t point) {
    return (point.get_x() >= min.get_x() && point.get_x() <= max.get_x()) &&
           (point.get_y() >= min.get_y() && point.get_y() <= max.get_y()) &&
           (point.get_z() >= min.get_z() && point.get_z() <= max.get_z());
}

OctTree::~OctTree() {
    for(int i = 0; i < 8; i++) {
        delete children_nodes[i];
    }
}

void OctTree::print_tree(int depth) const {
    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";
    }

    std::cout << "Node at depth " << depth << ":\n";
    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";
    }
    std::cout << "  Boundary: [" 
              << boundary.min.get_x() << " " << boundary.min.get_y() << " " << boundary.min.get_z() << ", " 
              << boundary.max.get_x() << " " << boundary.max.get_y() << " " << boundary.max.get_z() << "]\n";

    if (!local_triangles.empty()) {
        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }
        std::cout << "  Triangles: \n";
        for (const auto& triangle : local_triangles) {
            for (int i = 0; i < depth; ++i) {
                std::cout << "  ";
            }
            std::cout << "  " << triangle.num << "      " 
                      << triangle.triangle.get_a().get_x() << " " 
                      << triangle.triangle.get_a().get_y() << " " 
                      << triangle.triangle.get_a().get_z() << ", " 
                      << triangle.triangle.get_b().get_x() << " " 
                      << triangle.triangle.get_b().get_y() << " " 
                      << triangle.triangle.get_b().get_z() << ", " 
                      << triangle.triangle.get_c().get_x() << " " 
                      << triangle.triangle.get_c().get_y() << " " 
                      << triangle.triangle.get_c().get_z() << "\n";
        }
    } else {
        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }
        std::cout << "  No triangles in this node.\n";
    }

    for (int i = 0; i < 8; ++i) {
        if (children_nodes[i] != nullptr) {
            children_nodes[i]->print_tree(depth + 1);
        }
    }
}

void OctTree::build_tree() {
    if(local_triangles.size() <= 1)
        return;

    Point_t boundary_size = boundary.max - boundary.min;
    if(boundary_size.get_x() <= MIN_OCTANT_SIZE && boundary_size.get_y() <= MIN_OCTANT_SIZE
    && boundary_size.get_z() <= MIN_OCTANT_SIZE)
        return;

    Point_t half   = boundary_size * 0.5;
    Point_t center = boundary.min + half;

    BoundingBox octant[8];
    octant[0] = BoundingBox(boundary.min, center);
    octant[1] = BoundingBox({center.get_x(), boundary.min.get_y(), boundary.min.get_z()}, 
                            {boundary.max.get_x(), center.get_y(), center.get_z()});
    octant[2] = BoundingBox({center.get_x(), boundary.min.get_y(), center.get_z()},
                            {boundary.max.get_x(), center.get_y(), boundary.max.get_z()});
    octant[3] = BoundingBox({boundary.min.get_x(), boundary.min.get_y(), center.get_z()},
                            {center.get_x(), center.get_y(), boundary.max.get_z()});
    octant[4] = BoundingBox({boundary.min.get_x(), center.get_y(), boundary.min.get_z()},
                            {center.get_x(), boundary.max.get_y(), center.get_z()});
    octant[5] = BoundingBox({center.get_x(), center.get_y(), boundary.min.get_z()},
                            {boundary.max.get_x(), boundary.max.get_y(), center.get_z()});
    octant[6] = BoundingBox(center, boundary.max);
    octant[7] = BoundingBox({boundary.min.get_x(), center.get_y(), center.get_z()},
                            {center.get_x(), boundary.max.get_y(), boundary.max.get_z()});

    std::list<TriangleWithNum> oct_lists[8];
    for(auto local_triangle = local_triangles.begin(); local_triangle != local_triangles.end(); ++local_triangle) {
        for(int i = 0 ; i < 8; i ++) {
            if(octant[i].contains_triangle(local_triangle->triangle)) {
                oct_lists[i].push_back(*local_triangle);

                auto next_triangle = std::next(local_triangle);
                local_triangles.erase(local_triangle);
                local_triangle = next_triangle;

                break;
            }
        }
    }

    for(int i = 0; i < 8; i++) {
        if(oct_lists[i].size() != 0) {
            children_nodes[i] = new OctTree(octant[i], oct_lists[i]);
            children_nodes[i]->build_tree();
        }
    }
}

std::unordered_set<size_t> OctTree::get_intersection(std::list<TriangleWithNum>& parent_triangles) {
    std::unordered_set<size_t> intersections;

    for(auto parent_triangle = parent_triangles.begin(); parent_triangle != parent_triangles.end(); ++parent_triangle) {
        for(auto local_triangle = local_triangles.begin(); local_triangle != local_triangles.end(); ++local_triangle) {
            if(check_intersection(parent_triangle->triangle, local_triangle->triangle)) {
                intersections.insert(local_triangle->num);
                intersections.insert(parent_triangle->num);
            }
        }
    }

    for(auto local_triangle = local_triangles.begin(); local_triangle != local_triangles.end(); ++local_triangle) {
        for(auto tmp = std::next(local_triangle); tmp != local_triangles.end(); tmp++) {
            if(check_intersection(local_triangle->triangle, tmp->triangle)) {
                intersections.insert(local_triangle->num);
                intersections.insert(tmp->num);
            }
        }
    }

    parent_triangles.insert(parent_triangles.end(), local_triangles.begin(), local_triangles.end());

    for(int i = 0; i < 8; i++) {
        if(children_nodes[i]) {
            std::unordered_set<size_t> new_intersections = children_nodes[i]->get_intersection(parent_triangles);
            intersections.insert(new_intersections.begin(), new_intersections.end());
        }
    }

    return intersections;
}

std::unordered_set<size_t> OctTree::get_intersection()
{
    std::list<TriangleWithNum> parent_triangles;
    return get_intersection(parent_triangles);
}