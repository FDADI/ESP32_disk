idf_component_register(SRC_DIRS "." 
                       REQUIRES driver
                       INCLUDE_DIRS "." "../user_dev/SPI" ""
                       PRIV_REQUIRES user_dev driver)