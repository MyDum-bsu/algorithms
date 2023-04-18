cmake_minimum_required(VERSION 3.24)
project(irunner)

set(CMAKE_CXX_STANDARD 20)

set(common "kr1 kr2 trees dp_comm data_struct")
set(individual "dp bst data_structure string graphs")

set(dp "30.2_Parquet 89_Scoring-system 82_Piano")
set(bst "33")
set(data_structure "flood_it 48_archive")
set(string "choice")
set(graphs "stoplights excursion")
set(kr1 "task1 task2 task3")
set(kr2 "task1 task2")

set(dp_comm "69.2_Frog_way 0.2_Units 0.0 matrix lcs palindrome lis 25")
set(tress "bin_search build_tree is_search")
set(data_struct "is_heap huffman bin_heap sum hash")

foreach(theme IN LISTS individual)
    separate_arguments(${theme})
endforeach()

foreach(theme IN LISTS common)
    separate_arguments(${theme})
endforeach()

foreach(theme IN LISTS individual)
    foreach(project IN LISTS ${theme})
        set(project_name "${project}")
        message(STATUS "adding project ${project_name}")
        add_executable("${project_name}" "individual/${theme}/${project}/main.cpp")
    endforeach()
endforeach()

#foreach(project IN LISTS common)
#    set(project_name "${project}")
#    message(STATUS "adding project ${project_name}")
#    add_executable("${project_name}" "common/${project}/main.cpp")
#endforeach()

foreach(theme IN LISTS common)
    foreach(project IN LISTS ${theme})
        set(project_name "${project}")
        message(STATUS "adding project ${project_name}")
        add_executable("${project_name}" "common/${theme}/${project}/main.cpp")
    endforeach()
endforeach()