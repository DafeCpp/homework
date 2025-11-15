int get_max_element(int* array, int size)
{
    int max_element = array[0];
    for (int i{ 0 }; i < size; i++)
    {
        if (max_element < array[i])
            max_element = array[i];
    }
    return max_element;
};