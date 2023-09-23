file(GLOB_RECURSE SOURCES src/*.c)
file(GLOB_RECURSE LV_DEV_SOURCES lvgl_driver/*.c)
file(GLOB_RECURSE LV_DEV_USER_LV_FONT user_lv_font/*.c)
file(GLOB_RECURSE LV_DEV_USER_LV_IMG user_lv_img/*.c)
file(GLOB_RECURSE DEMOS demos/*.c)


idf_component_register(	SRCS ${SOURCES}
						SRCS ${LV_DEV_SOURCES}
						SRCS ${LV_DEV_USER_LV_FONT}
						SRCS ${LV_DEV_USER_LV_IMG}
						SRCS ${DEMOS}
						INCLUDE_DIRS ./src ../ ./lvgl_driver  demos 
                       	PRIV_REQUIRES driver ) 

# idf_component_register(
						
# 						SRC_DIRS "src/core"
# 						SRC_DIRS "src/draw"
# 						SRC_DIRS "src/font"
# 						SRC_DIRS "src/hal"
# 						SRC_DIRS "src/misc"
# 						SRC_DIRS "src/widgets"
# 						SRC_DIRS "src/extra"
# 						SRC_DIRS "src/extra/layouts"
# 						SRC_DIRS "src/extra/layouts/flex"
# 						SRC_DIRS "src/extra/layouts/grid"
# 						SRC_DIRS "src/extra/libs"
# 						SRC_DIRS "src/extra/others"
# 						SRC_DIRS "src/extra/themes"
# 						SRC_DIRS "src/extra/themes/basic"
# 						SRC_DIRS "src/extra/themes/default"
# 						SRC_DIRS "src/extra/themes/mono"
# 						SRC_DIRS "src/extra/widgets"
# 						SRC_DIRS "src/extra/widgets/animimg"
# 						SRC_DIRS "src/extra/widgets/calendar"
# 						SRC_DIRS "src/extra/widgets/chart"
# 						SRC_DIRS "src/extra/widgets/colorwheel"
# 						SRC_DIRS "src/extra/widgets/imgbtn"
# 						SRC_DIRS "src/extra/widgets/keyboard"
# 						SRC_DIRS "src/extra/widgets/led"
# 						SRC_DIRS "src/extra/widgets/list"
# 						SRC_DIRS "src/extra/widgets/menu"
# 						SRC_DIRS "src/extra/widgets/meter"
# 						SRC_DIRS "src/extra/widgets/msgbox"
# 						SRC_DIRS "src/extra/widgets/span"
# 						SRC_DIRS "src/extra/widgets/spinbox"
# 						SRC_DIRS "src/extra/widgets/spinner"
# 						SRC_DIRS "src/extra/widgets/tabview"
# 						SRC_DIRS "src/extra/widgets/win"

# 						SRC_DIRS "lvgl_driver"
# 						SRC_DIRS "demos"
# 						SRC_DIRS "demos/benchmark"
# 						SRC_DIRS "demos/keypad_encoder"
# 						SRC_DIRS "demos/music"
# 						SRC_DIRS "demos/stress"
# 						SRC_DIRS "demos/widgets"
# 						INCLUDE_DIRS "./"
# 						PRIV_REQUIRES driver
# )