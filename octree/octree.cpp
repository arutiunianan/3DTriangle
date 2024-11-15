#include "octree.h"

bool BoundingBox::contains_triangle(const Triangle_t& triangle)
{
    return contains_point(triangle.a) &&
           contains_point(triangle.b) &&
           contains_point(triangle.c);
}
bool BoundingBox::contains_point(const Point_t& point) const
{
    return (point.x >= min.x && point.x <= max.x) &&
           (point.y >= min.y && point.y <= max.y) &&
           (point.z >= min.z && point.z <= max.z);
}

OctTree::~OctTree()
{
    for (int i = 0; i < 8; i++)
    {
        delete children_nodes[i];
    }
}

void OctTree::build_tree()
{
    if(local_triangles.size() <= 1)
        return;

    Point_t boundary_size = boundary.max - boundary.min;
    if(boundary_size.x <= MIN_OCTANT_SIZE && boundary_size.y <= MIN_OCTANT_SIZE
    && boundary_size.z <= MIN_OCTANT_SIZE)
        return;

    Point_t half   = boundary_size * 0.5;
    Point_t center = boundary.min + half;

    BoundingBox octant[8];
    octant[0] = BoundingBox(boundary.min, center);
    octant[1] = BoundingBox({center.x, boundary.min.y, boundary.min.z}, 
                            {boundary.max.x, center.y, center.z});
    octant[2] = BoundingBox({center.x, boundary.min.y, center.z},
                            {boundary.max.x, center.y, boundary.max.z});
    octant[3] = BoundingBox({boundary.min.x, boundary.min.y, center.z},
                            {center.x, center.y, boundary.max.z});
    octant[4] = BoundingBox({boundary.min.x, center.y, boundary.min.z},
                            {center.x, boundary.max.y, center.z});
    octant[5] = BoundingBox({center.x, center.y, boundary.min.z},
                            {boundary.max.x, boundary.max.y, center.z});
    octant[6] = BoundingBox(center, boundary.max);
    octant[7] = BoundingBox({boundary.min.x, center.y, center.z},
                            {center.x, boundary.max.y, boundary.max.z});

    std::list<TriangleWithNum> oct_lists[8];
    for (auto local_triangle = local_triangles.begin(); local_triangle != local_triangles.end(); ++local_triangle)
    {
        for (int i = 0 ; i < 8; i ++)
        {
            if(octant[i].contains_triangle(local_triangle->triangle))
            {
                oct_lists[i].push_back(*local_triangle);

                auto next_triangle = std::next(local_triangle);
                local_triangles.erase(local_triangle);
                local_triangle = next_triangle;

                break;
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        if (oct_lists[i].size() != 0)
        {
            children_nodes[i] = new OctTree(octant[i], oct_lists[i]);
            children_nodes[i]->build_tree();
        }
    }
}

std::unordered_set<size_t> OctTree::get_intersection(std::list<TriangleWithNum>& parent_triangles)
{
    std::unordered_set<size_t> intersections;

    for (auto parent_triangle = parent_triangles.begin(); parent_triangle != parent_triangles.end(); ++parent_triangle)
    {
        for (auto local_triangle = local_triangles.begin(); local_triangle != local_triangles.end(); ++local_triangle)
        {
            if(check_intersection(parent_triangle->triangle, local_triangle->triangle))
            {
                intersections.insert(local_triangle->num);
                intersections.insert(parent_triangle->num);
            }
        }
    }

    for (auto local_triangle = local_triangles.begin(); local_triangle != local_triangles.end(); ++local_triangle)
    {
        for(auto tmp = std::next(local_triangle); tmp != local_triangles.end(); tmp++)
        {
            if(check_intersection(local_triangle->triangle, tmp->triangle))
            {
                intersections.insert(local_triangle->num);
                intersections.insert(tmp->num);
            }
        }
    }

    parent_triangles.insert(parent_triangles.end(), local_triangles.begin(), local_triangles.end());

    for(int i = 0; i < 8; i++)
    {
        if(children_nodes[i] && children_nodes[i]->local_triangles.size() > 0)
        {
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