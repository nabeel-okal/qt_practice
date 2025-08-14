include("/home/nabeel_okal/Qt_Projects/MainWindow_prototype/build/Desktop_Qt_6_9_1-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/MainWindow_prototype-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE /home/nabeel_okal/Qt_Projects/MainWindow_prototype/build/Desktop_Qt_6_9_1-Debug/MainWindow_prototype
    GENERATE_QT_CONF
)
