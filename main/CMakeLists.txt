set(component_srcs "main.c" "dhrystone.c" "whetstone.c")

idf_component_register(SRCS "${component_srcs}" INCLUDE_DIRS ".")

