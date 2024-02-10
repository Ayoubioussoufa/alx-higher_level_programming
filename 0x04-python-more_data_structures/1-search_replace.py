#!/usr/bin/python3
def search_replace(my_list, search, replace):
    lists = my_list[:]
    lists = [replace if x == search else x for x in lists]
    return lists
