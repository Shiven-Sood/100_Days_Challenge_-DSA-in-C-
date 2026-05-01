def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2

        # Divide
        left = arr[:mid]
        right = arr[mid:]

        # Sort halves
        merge_sort(left)
        merge_sort(right)

        # Merge
        i = j = k = 0

        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arr[k] = left[i]
                i += 1
            else:
                arr[k] = right[j]
                j += 1
            k += 1

        # Remaining elements
        while i < len(left):
            arr[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            arr[k] = right[j]
            j += 1
            k += 1


# Input array
arr = [38, 27, 43, 3, 9, 82, 10]

# Call merge sort
merge_sort(arr)

# Print sorted array
print("Sorted array:", arr)
