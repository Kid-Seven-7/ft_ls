ft_ls synopsis

main.c
	-calls read_into_dir

read_into_dir.c
	-calls opendir to open the directory
	-calls readdir to read the content of the directory
	-calls lstnew to create a list if the head is NULL
	-calls ft_lstadd_to_head([list], [content_to_add])
	-calls closedir to dir the opened directory
	-calls ft_putendl to print out heads content

ft_lstadd_to_head.c
	-calls ft_lstnew to create a node to add to the head of the list
