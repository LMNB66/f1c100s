SET(SOURCES screens/ui_home.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_bg_png.c
    images/ui_img_1287868244.c
    images/ui_img_232707142.c
    images/ui_img_1026557178.c
    images/ui_img_242428017.c
    images/ui_img_902424251.c
    images/ui_img_83633437.c
    images/ui_img_72425762.c
    images/ui_img_453075344.c
    images/ui_img_1656800463.c
    images/ui_img_1895014438.c
    images/ui_img_364366452.c
    images/ui_img_1909428037.c
    images/ui_img_213399634.c
    fonts/ui_font_sonti_14.c
    fonts/ui_font_sonti_16.c
    fonts/ui_font_sonti_18.c)

add_library(ui ${SOURCES})
