set(pri_req nvs_flash driver)
idf_component_register(SRCS "utils.c" 
                    INCLUDE_DIRS "."
                    REQUIRES ${pre_req})