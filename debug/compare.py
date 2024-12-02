def read_numbers_from_file(filename):
    try:
        with open(filename, 'r') as file:
            numbers = set(int(line.strip()) for line in file)
        return numbers
    except FileNotFoundError:
        print(f"Не удалось открыть файл: {filename}")
        exit(1)

def compare_numbers(numbers1, numbers2):
    unique_to_file1 = numbers1 - numbers2
    unique_to_file2 = numbers2 - numbers1
    return unique_to_file1, unique_to_file2

def main():
    import sys

    if len(sys.argv) != 3:
        print(f"Использование: {sys.argv[0]} <file1> <file2>")
        return 1

    numbers1 = read_numbers_from_file(sys.argv[1])
    
    numbers2 = read_numbers_from_file(sys.argv[2])

    unique_to_file1, unique_to_file2 = compare_numbers(numbers1, numbers2)

    if numbers1 == numbers2:
        print("Числа в файлах одинаковые.")
    else:
        print("Числа в файлах различаются.")

        if unique_to_file1:
            print(f"Числа, которые есть только в {sys.argv[1]}: {sorted(unique_to_file1)}")
        
        if unique_to_file2:
            print(f"Числа, которые есть только в {sys.argv[2]}: {sorted(unique_to_file2)}")

if __name__ == "__main__":
    main()