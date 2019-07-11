/********************************************************************************
** Form generated from reading UI file 'DatabaseViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEVIEWER_H
#define UI_DATABASEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../include/rtabmap/gui/GraphViewer.h"
#include "../include/rtabmap/gui/ImageView.h"
#include "../include/rtabmap/gui/ParametersToolBox.h"
#include "../include/rtabmap/gui/StatsToolBox.h"

QT_BEGIN_NAMESPACE

class Ui_DatabaseViewer
{
public:
    QAction *actionOpen_database;
    QAction *actionQuit;
    QAction *actionGenerate_graph_dot;
    QAction *actionGenerate_local_graph_dot;
    QAction *actionGenerate_3D_map_pcd;
    QAction *actionExport;
    QAction *actionExtract_images;
    QAction *actionView_3D_map;
    QAction *actionRefine_all_neighbor_links;
    QAction *actionRefine_all_loop_closure_links;
    QAction *actionDetect_more_loop_closures;
    QAction *actionSave_config;
    QAction *actionReset_all_changes;
    QAction *actionRegenerate_local_grid_maps;
    QAction *actionRegenerate_local_grid_maps_selected;
    QAction *actionEdit_depth_image;
    QAction *actionVertical_Layout;
    QAction *actionRestore_default_GUI_settings;
    QAction *actionRaw_format_txt;
    QAction *actionRGBD_SLAM_format_txt;
    QAction *actionKITTI_format_txt;
    QAction *actionTORO_graph;
    QAction *actionG2o_g2o;
    QAction *actionGPS_KML;
    QAction *actionGPS_TXT;
    QAction *actionPoses_KML;
    QAction *actionDatabase_recovery;
    QAction *actionClose_database;
    QAction *actionExport_saved_2D_map;
    QAction *actionImport_2D_map;
    QAction *actionView_optimized_mesh;
    QAction *actionExport_optimized_mesh;
    QAction *actionUpdate_optimized_mesh;
    QAction *actionUpdate_all_neighbor_covariances;
    QAction *actionUpdate_all_loop_closure_covariances;
    QAction *actionRGBD_SLAM_motion_capture_format_txt;
    QAction *actionEdit_optimized_2D_map;
    QAction *actionRegenerate_optimized_2D_map;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_imageViews;
    rtabmap::ImageView *graphicsView_A;
    rtabmap::ImageView *graphicsView_B;
    QGridLayout *gridLayout_11;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout;
    QLabel *label_poseA;
    QLabel *label_childrenA_2;
    QLabel *label_parentsA;
    QLabel *label_parentsA_2;
    QLabel *label_childrenA_12;
    QLabel *label_mapA;
    QLabel *label_childrenA_10;
    QLabel *label_childrenA_14;
    QLabel *label_calibA;
    QLabel *label_childrenA;
    QLabel *label_childrenA_4;
    QLabel *label_labelA;
    QLabel *label_childrenA_6;
    QLabel *label_stampA;
    QLabel *label_childrenA_8;
    QLabel *label_weightA;
    QLabel *label_childrenA_16;
    QLabel *label_gpsA;
    QLabel *label_childrenA_18;
    QLabel *label_velA;
    QLabel *label_childrenA_20;
    QLabel *label_sensorsA;
    QLabel *label_childrenA_22;
    QLabel *label_scanA;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QLabel *label_childrenA_9;
    QLabel *label_mapB;
    QLabel *label_poseB;
    QLabel *label_childrenA_15;
    QLabel *label_calibB;
    QLabel *label_childrenA_17;
    QLabel *label_gpsB;
    QLabel *label_childrenB;
    QLabel *label_childrenA_5;
    QLabel *label_labelB;
    QLabel *label_weightB;
    QLabel *label_childrenA_11;
    QLabel *label_childrenA_13;
    QLabel *label_parentsB;
    QLabel *label_parentsA_4;
    QLabel *label_childrenA_3;
    QLabel *label_childrenA_7;
    QLabel *label_stampB;
    QLabel *label_childrenA_19;
    QLabel *label_velB;
    QLabel *label_childrenA_21;
    QLabel *label_sensorsB;
    QLabel *label_childrenA_23;
    QLabel *label_scanB;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_indexA;
    QLabel *label_idA;
    QSlider *horizontalSlider_A;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_indexB;
    QLabel *label_idB;
    QSlider *horizontalSlider_B;
    QDialogButtonBox *buttonBox;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuExport_poses;
    QMenu *menuExport_GPS;
    QMenu *menuEdit;
    QMenu *menuView;
    QDockWidget *dockWidget_constraints;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *layout_constraintsViewer;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *checkBox_show3DWords;
    QCheckBox *checkBox_show3Dclouds;
    QCheckBox *checkBox_show2DScans;
    QCheckBox *checkBox_odomFrame;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_variance;
    QLineEdit *lineEdit_covariance;
    QLabel *label;
    QSlider *horizontalSlider_neighbors;
    QLabel *label_6;
    QSlider *horizontalSlider_loops;
    QLabel *label_33;
    QLabel *label_16;
    QLabel *label_constraint;
    QCheckBox *checkBox_showOptimized;
    QLabel *label_constraint_opt;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_type;
    QLabel *label_type_name;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_refine;
    QPushButton *pushButton_reset;
    QPushButton *pushButton_add;
    QPushButton *pushButton_reject;
    QSpacerItem *horizontalSpacer;
    QDockWidget *dockWidget_graphView;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_9;
    rtabmap::GraphViewer *graphViewer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_iterations;
    QSlider *horizontalSlider_iterations;
    QCheckBox *checkBox_iterativeOptimization;
    QGridLayout *gridLayout_5;
    QLabel *label_loopClosures;
    QLabel *label_timeGrid;
    QLabel *label_timeOptimization;
    QSpinBox *spinBox_optimizationsFrom;
    QLabel *label_52;
    QLabel *label_39;
    QLabel *label_41;
    QLabel *label_10;
    QLabel *label_45;
    QLabel *label_pathLength;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_optimizeFrom;
    QCheckBox *checkBox_spanAllMaps;
    QCheckBox *checkBox_wmState;
    QLabel *label_poses;
    QLabel *label_alignPosesWithGroundTruth;
    QCheckBox *checkBox_ignoreIntermediateNodes;
    QCheckBox *checkBox_alignPosesWithGroundTruth;
    QLabel *label_rmse;
    QLabel *label_ignoreINtermediateNdoes;
    QLabel *label_rmse_title;
    QLabel *label_alignScansCloudsWithGroundTruth;
    QCheckBox *checkBox_alignScansCloudsWithGroundTruth;
    QDockWidget *dockWidget_guiparameters;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_10;
    QGridLayout *gridLayout_4;
    QComboBox *comboBox_logger_level;
    QLabel *label_logger_level;
    QToolBox *toolBox;
    QWidget *page_3;
    QGridLayout *gridLayout_7;
    QCheckBox *checkBox_ignoreGlobalLoop;
    QLabel *label_49;
    QCheckBox *checkBox_ignoreLocalLoopSpace;
    QLabel *label_48;
    QLabel *label_35;
    QCheckBox *checkBox_ignorePoseCorrection;
    QCheckBox *checkBox_ignoreLocalLoopTime;
    QSpacerItem *verticalSpacer_3;
    QCheckBox *checkBox_ignoreUserLoop;
    QLabel *label_50;
    QLabel *label_47;
    QLabel *label_scale_title;
    QDoubleSpinBox *doubleSpinBox_optimizationScale;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_16;
    QGridLayout *gridLayout_9;
    QLabel *label_51;
    QDoubleSpinBox *doubleSpinBox_gainCompensationRadius;
    QLabel *label_53;
    QLabel *label_54;
    QCheckBox *checkBox_octomap;
    QCheckBox *checkBox_grid_regenerateFromSavedGrid;
    QDoubleSpinBox *doubleSpinBox_voxelSize;
    QSpinBox *spinBox_grid_depth;
    QCheckBox *checkBox_grid_empty;
    QLabel *label_octomap_cubes;
    QComboBox *comboBox_octomap_rendering_type;
    QLabel *label_octomap_depth;
    QLabel *label_55;
    QLabel *label_octomap_empty;
    QLabel *label_octomap_empty_3;
    QLabel *label_octomap_empty_2;
    QLabel *label_octomap_empty_4;
    QHBoxLayout *horizontalLayout_9;
    QToolButton *toolButton_groundColor;
    QLineEdit *lineEdit_groundColor;
    QHBoxLayout *horizontalLayout_11;
    QToolButton *toolButton_obstacleColor;
    QLineEdit *lineEdit_obstacleColor;
    QHBoxLayout *horizontalLayout_12;
    QToolButton *toolButton_emptyColor;
    QLineEdit *lineEdit_emptyColor;
    QLabel *label_56;
    QSpinBox *spinBox_decimation;
    QGroupBox *groupBox_posefiltering;
    QGridLayout *gridLayout_12;
    QDoubleSpinBox *doubleSpinBox_posefilteringAngle;
    QDoubleSpinBox *doubleSpinBox_posefilteringRadius;
    QLabel *label_42;
    QLabel *label_43;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_13;
    QLabel *label_14;
    QLabel *label_12;
    QSpinBox *spinBox_mesh_angleTolerance;
    QSpinBox *spinBox_mesh_triangleSize;
    QLabel *label_13;
    QLabel *label_17;
    QSpinBox *spinBox_mesh_depthError;
    QCheckBox *checkBox_mesh_quad;
    QLabel *label_15;
    QSpinBox *spinBox_mesh_fillDepthHoles;
    QLabel *label_20;
    QSpinBox *spinBox_mesh_minClusterSize;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_5;
    QGridLayout *gridLayout_10;
    QLabel *label_32;
    QDoubleSpinBox *doubleSpinBox_detectMore_radius;
    QLabel *label_29;
    QDoubleSpinBox *doubleSpinBox_detectMore_angle;
    QLabel *label_30;
    QSpinBox *spinBox_detectMore_iterations;
    QLabel *label_31;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_34;
    QCheckBox *checkBox_detectMore_intraSession;
    QCheckBox *checkBox_detectMore_interSession;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QSpinBox *spinBox_icp_decimation;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_icp_maxDepth;
    QLabel *label_11;
    QCheckBox *checkBox_icp_from_depth;
    QLabel *label_7;
    QSpacerItem *verticalSpacer;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBox_icp_minDepth;
    QDockWidget *dockWidget_stereoView;
    QWidget *dockWidgetContents_stereo;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_stereo;
    rtabmap::ImageView *graphicsView_stereo;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_stereo_inliers_name;
    QLabel *label_stereo_inliers;
    QLabel *label_stereo_slopeOutliers_name;
    QLabel *label_stereo_slopeOutliers;
    QLabel *label_stereo_disparityOutliers_name;
    QLabel *label_stereo_disparityOutliers;
    QLabel *label_stereo_flowOutliers_name;
    QLabel *label_stereo_flowOutliers;
    QSpacerItem *horizontalSpacer_2;
    QDockWidget *dockWidget_view3d;
    QWidget *dockWidgetContents_3dviews;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3dviews;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_showWords;
    QCheckBox *checkBox_showCloud;
    QCheckBox *checkBox_showMesh;
    QCheckBox *checkBox_showScan;
    QCheckBox *checkBox_showMap;
    QCheckBox *checkBox_showGrid;
    QCheckBox *checkBox_odomFrame_3dview;
    QSpacerItem *horizontalSpacer_4;
    QDockWidget *dockWidget_info;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_12;
    QTextEdit *textEdit_info;
    QDockWidget *dockWidget_coreparameters;
    QWidget *dockWidgetContents_7;
    QVBoxLayout *verticalLayout_13;
    rtabmap::ParametersToolBox *parameters_toolbox;
    QDockWidget *dockWidget_statistics;
    QWidget *dockWidgetContents_5;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_8;
    QCheckBox *checkBox_timeStats;
    QLabel *label_logger_level_3;
    rtabmap::StatsToolBox *toolBox_statistics;
    QDockWidget *dockWidget_occupancyGridView;
    QWidget *dockWidgetContents_occupancyGrid;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *layout_occupancyGridView;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *checkBox_grid_2d;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QMainWindow *DatabaseViewer)
    {
        if (DatabaseViewer->objectName().isEmpty())
            DatabaseViewer->setObjectName(QStringLiteral("DatabaseViewer"));
        DatabaseViewer->resize(1547, 965);
        DatabaseViewer->setLayoutDirection(Qt::LeftToRight);
        actionOpen_database = new QAction(DatabaseViewer);
        actionOpen_database->setObjectName(QStringLiteral("actionOpen_database"));
        actionQuit = new QAction(DatabaseViewer);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionGenerate_graph_dot = new QAction(DatabaseViewer);
        actionGenerate_graph_dot->setObjectName(QStringLiteral("actionGenerate_graph_dot"));
        actionGenerate_local_graph_dot = new QAction(DatabaseViewer);
        actionGenerate_local_graph_dot->setObjectName(QStringLiteral("actionGenerate_local_graph_dot"));
        actionGenerate_3D_map_pcd = new QAction(DatabaseViewer);
        actionGenerate_3D_map_pcd->setObjectName(QStringLiteral("actionGenerate_3D_map_pcd"));
        actionExport = new QAction(DatabaseViewer);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionExtract_images = new QAction(DatabaseViewer);
        actionExtract_images->setObjectName(QStringLiteral("actionExtract_images"));
        actionView_3D_map = new QAction(DatabaseViewer);
        actionView_3D_map->setObjectName(QStringLiteral("actionView_3D_map"));
        actionRefine_all_neighbor_links = new QAction(DatabaseViewer);
        actionRefine_all_neighbor_links->setObjectName(QStringLiteral("actionRefine_all_neighbor_links"));
        actionRefine_all_loop_closure_links = new QAction(DatabaseViewer);
        actionRefine_all_loop_closure_links->setObjectName(QStringLiteral("actionRefine_all_loop_closure_links"));
        actionDetect_more_loop_closures = new QAction(DatabaseViewer);
        actionDetect_more_loop_closures->setObjectName(QStringLiteral("actionDetect_more_loop_closures"));
        actionSave_config = new QAction(DatabaseViewer);
        actionSave_config->setObjectName(QStringLiteral("actionSave_config"));
        actionReset_all_changes = new QAction(DatabaseViewer);
        actionReset_all_changes->setObjectName(QStringLiteral("actionReset_all_changes"));
        actionRegenerate_local_grid_maps = new QAction(DatabaseViewer);
        actionRegenerate_local_grid_maps->setObjectName(QStringLiteral("actionRegenerate_local_grid_maps"));
        actionRegenerate_local_grid_maps_selected = new QAction(DatabaseViewer);
        actionRegenerate_local_grid_maps_selected->setObjectName(QStringLiteral("actionRegenerate_local_grid_maps_selected"));
        actionEdit_depth_image = new QAction(DatabaseViewer);
        actionEdit_depth_image->setObjectName(QStringLiteral("actionEdit_depth_image"));
        actionVertical_Layout = new QAction(DatabaseViewer);
        actionVertical_Layout->setObjectName(QStringLiteral("actionVertical_Layout"));
        actionVertical_Layout->setCheckable(true);
        actionVertical_Layout->setChecked(true);
        actionRestore_default_GUI_settings = new QAction(DatabaseViewer);
        actionRestore_default_GUI_settings->setObjectName(QStringLiteral("actionRestore_default_GUI_settings"));
        actionRaw_format_txt = new QAction(DatabaseViewer);
        actionRaw_format_txt->setObjectName(QStringLiteral("actionRaw_format_txt"));
        actionRGBD_SLAM_format_txt = new QAction(DatabaseViewer);
        actionRGBD_SLAM_format_txt->setObjectName(QStringLiteral("actionRGBD_SLAM_format_txt"));
        actionKITTI_format_txt = new QAction(DatabaseViewer);
        actionKITTI_format_txt->setObjectName(QStringLiteral("actionKITTI_format_txt"));
        actionTORO_graph = new QAction(DatabaseViewer);
        actionTORO_graph->setObjectName(QStringLiteral("actionTORO_graph"));
        actionG2o_g2o = new QAction(DatabaseViewer);
        actionG2o_g2o->setObjectName(QStringLiteral("actionG2o_g2o"));
        actionGPS_KML = new QAction(DatabaseViewer);
        actionGPS_KML->setObjectName(QStringLiteral("actionGPS_KML"));
        actionGPS_TXT = new QAction(DatabaseViewer);
        actionGPS_TXT->setObjectName(QStringLiteral("actionGPS_TXT"));
        actionPoses_KML = new QAction(DatabaseViewer);
        actionPoses_KML->setObjectName(QStringLiteral("actionPoses_KML"));
        actionDatabase_recovery = new QAction(DatabaseViewer);
        actionDatabase_recovery->setObjectName(QStringLiteral("actionDatabase_recovery"));
        actionClose_database = new QAction(DatabaseViewer);
        actionClose_database->setObjectName(QStringLiteral("actionClose_database"));
        actionExport_saved_2D_map = new QAction(DatabaseViewer);
        actionExport_saved_2D_map->setObjectName(QStringLiteral("actionExport_saved_2D_map"));
        actionImport_2D_map = new QAction(DatabaseViewer);
        actionImport_2D_map->setObjectName(QStringLiteral("actionImport_2D_map"));
        actionView_optimized_mesh = new QAction(DatabaseViewer);
        actionView_optimized_mesh->setObjectName(QStringLiteral("actionView_optimized_mesh"));
        actionExport_optimized_mesh = new QAction(DatabaseViewer);
        actionExport_optimized_mesh->setObjectName(QStringLiteral("actionExport_optimized_mesh"));
        actionUpdate_optimized_mesh = new QAction(DatabaseViewer);
        actionUpdate_optimized_mesh->setObjectName(QStringLiteral("actionUpdate_optimized_mesh"));
        actionUpdate_all_neighbor_covariances = new QAction(DatabaseViewer);
        actionUpdate_all_neighbor_covariances->setObjectName(QStringLiteral("actionUpdate_all_neighbor_covariances"));
        actionUpdate_all_loop_closure_covariances = new QAction(DatabaseViewer);
        actionUpdate_all_loop_closure_covariances->setObjectName(QStringLiteral("actionUpdate_all_loop_closure_covariances"));
        actionRGBD_SLAM_motion_capture_format_txt = new QAction(DatabaseViewer);
        actionRGBD_SLAM_motion_capture_format_txt->setObjectName(QStringLiteral("actionRGBD_SLAM_motion_capture_format_txt"));
        actionEdit_optimized_2D_map = new QAction(DatabaseViewer);
        actionEdit_optimized_2D_map->setObjectName(QStringLiteral("actionEdit_optimized_2D_map"));
        actionRegenerate_optimized_2D_map = new QAction(DatabaseViewer);
        actionRegenerate_optimized_2D_map->setObjectName(QStringLiteral("actionRegenerate_optimized_2D_map"));
        centralwidget = new QWidget(DatabaseViewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_imageViews = new QHBoxLayout();
        horizontalLayout_imageViews->setObjectName(QStringLiteral("horizontalLayout_imageViews"));
        graphicsView_A = new rtabmap::ImageView(centralwidget);
        graphicsView_A->setObjectName(QStringLiteral("graphicsView_A"));

        horizontalLayout_imageViews->addWidget(graphicsView_A);

        graphicsView_B = new rtabmap::ImageView(centralwidget);
        graphicsView_B->setObjectName(QStringLiteral("graphicsView_B"));

        horizontalLayout_imageViews->addWidget(graphicsView_B);

        horizontalLayout_imageViews->setStretch(0, 1);
        horizontalLayout_imageViews->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout_imageViews);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(0);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        scrollArea_2 = new QScrollArea(centralwidget);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 409, 288));
        gridLayout = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_poseA = new QLabel(scrollAreaWidgetContents_2);
        label_poseA->setObjectName(QStringLiteral("label_poseA"));
        label_poseA->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(label_poseA, 5, 1, 1, 1);

        label_childrenA_2 = new QLabel(scrollAreaWidgetContents_2);
        label_childrenA_2->setObjectName(QStringLiteral("label_childrenA_2"));

        gridLayout->addWidget(label_childrenA_2, 1, 0, 1, 1);

        label_parentsA = new QLabel(scrollAreaWidgetContents_2);
        label_parentsA->setObjectName(QStringLiteral("label_parentsA"));
        label_parentsA->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(label_parentsA, 0, 1, 1, 1);

        label_parentsA_2 = new QLabel(scrollAreaWidgetContents_2);
        label_parentsA_2->setObjectName(QStringLiteral("label_parentsA_2"));

        gridLayout->addWidget(label_parentsA_2, 0, 0, 1, 1);

        label_childrenA_12 = new QLabel(scrollAreaWidgetContents_2);
        label_childrenA_12->setObjectName(QStringLiteral("label_childrenA_12"));

        gridLayout->addWidget(label_childrenA_12, 5, 0, 1, 1);

        label_mapA = new QLabel(scrollAreaWidgetContents_2);
        label_mapA->setObjectName(QStringLiteral("label_mapA"));
        label_mapA->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(label_mapA, 4, 1, 1, 1);

        label_childrenA_10 = new QLabel(scrollAreaWidgetContents_2);
        label_childrenA_10->setObjectName(QStringLiteral("label_childrenA_10"));

        gridLayout->addWidget(label_childrenA_10, 4, 0, 1, 1);

        label_childrenA_14 = new QLabel(scrollAreaWidgetContents_2);
        label_childrenA_14->setObjectName(QStringLiteral("label_childrenA_14"));

        gridLayout->addWidget(label_childrenA_14, 8, 0, 1, 1);

        label_calibA = new QLabel(scrollAreaWidgetContents_2);
        label_calibA->setObjectName(QStringLiteral("label_calibA"));
        label_calibA->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(label_calibA, 8, 1, 1, 1);

        label_childrenA = new QLabel(scrollAreaWidgetContents_2);
        label_childrenA->setObjectName(QStringLiteral("label_childrenA"));
        label_childrenA->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(label_childrenA, 1, 1, 1, 1);

        label_childrenA_4 = new QLabel(scrollAreaWidgetContents_2);
        label_childrenA_4->setObjectName(QStringLiteral("label_childrenA_4"));

        gridLayout->addWidget(label_childrenA_4, 3, 0, 1, 1);

        label_labelA = new QLabel(scrollAreaWidgetContents_2);
        label_labelA->setObjectName(QStringLiteral("label_labelA"));
        label_labelA->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(label_labelA, 3, 1, 1, 1);

        label_childrenA_6 = new QLabel(scrollAreaWidgetContents_2);
        label_childrenA_6->setObjectName(QStringLiteral("label_childrenA_6"));

        gridLayout->addWidget(label_childrenA_6, 7, 0, 1, 1);

        label_stampA = new QLabel(scrollAreaWidgetContents_2);
        label_stampA->setObjectName(QStringLiteral("label_stampA"));
        label_stampA->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(label_stampA, 7, 1, 1, 1);

        label_childrenA_8 = new QLabel(scrollAreaWidgetContents_2);
        label_childrenA_8->setObjectName(QStringLiteral("label_childrenA_8"));

        gridLayout->addWidget(label_childrenA_8, 2, 0, 1, 1);

        label_weightA = new QLabel(scrollAreaWidgetContents_2);
        label_weightA->setObjectName(QStringLiteral("label_weightA"));
        label_weightA->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(label_weightA, 2, 1, 1, 1);

        label_childrenA_16 = new QLabel(scrollAreaWidgetContents_2);
        label_childrenA_16->setObjectName(QStringLiteral("label_childrenA_16"));

        gridLayout->addWidget(label_childrenA_16, 10, 0, 1, 1);

        label_gpsA = new QLabel(scrollAreaWidgetContents_2);
        label_gpsA->setObjectName(QStringLiteral("label_gpsA"));
        label_gpsA->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(label_gpsA, 10, 1, 1, 1);

        label_childrenA_18 = new QLabel(scrollAreaWidgetContents_2);
        label_childrenA_18->setObjectName(QStringLiteral("label_childrenA_18"));

        gridLayout->addWidget(label_childrenA_18, 6, 0, 1, 1);

        label_velA = new QLabel(scrollAreaWidgetContents_2);
        label_velA->setObjectName(QStringLiteral("label_velA"));
        label_velA->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(label_velA, 6, 1, 1, 1);

        label_childrenA_20 = new QLabel(scrollAreaWidgetContents_2);
        label_childrenA_20->setObjectName(QStringLiteral("label_childrenA_20"));

        gridLayout->addWidget(label_childrenA_20, 11, 0, 1, 1);

        label_sensorsA = new QLabel(scrollAreaWidgetContents_2);
        label_sensorsA->setObjectName(QStringLiteral("label_sensorsA"));
        label_sensorsA->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(label_sensorsA, 11, 1, 1, 1);

        label_childrenA_22 = new QLabel(scrollAreaWidgetContents_2);
        label_childrenA_22->setObjectName(QStringLiteral("label_childrenA_22"));

        gridLayout->addWidget(label_childrenA_22, 9, 0, 1, 1);

        label_scanA = new QLabel(scrollAreaWidgetContents_2);
        label_scanA->setObjectName(QStringLiteral("label_scanA"));
        label_scanA->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout->addWidget(label_scanA, 9, 1, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_11->addWidget(scrollArea_2, 0, 0, 1, 1);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 408, 288));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_childrenA_9 = new QLabel(scrollAreaWidgetContents);
        label_childrenA_9->setObjectName(QStringLiteral("label_childrenA_9"));

        gridLayout_2->addWidget(label_childrenA_9, 2, 0, 1, 1);

        label_mapB = new QLabel(scrollAreaWidgetContents);
        label_mapB->setObjectName(QStringLiteral("label_mapB"));
        label_mapB->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_mapB, 4, 1, 1, 1);

        label_poseB = new QLabel(scrollAreaWidgetContents);
        label_poseB->setObjectName(QStringLiteral("label_poseB"));
        label_poseB->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_poseB, 5, 1, 1, 1);

        label_childrenA_15 = new QLabel(scrollAreaWidgetContents);
        label_childrenA_15->setObjectName(QStringLiteral("label_childrenA_15"));

        gridLayout_2->addWidget(label_childrenA_15, 8, 0, 1, 1);

        label_calibB = new QLabel(scrollAreaWidgetContents);
        label_calibB->setObjectName(QStringLiteral("label_calibB"));
        label_calibB->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_calibB, 8, 1, 1, 1);

        label_childrenA_17 = new QLabel(scrollAreaWidgetContents);
        label_childrenA_17->setObjectName(QStringLiteral("label_childrenA_17"));

        gridLayout_2->addWidget(label_childrenA_17, 10, 0, 1, 1);

        label_gpsB = new QLabel(scrollAreaWidgetContents);
        label_gpsB->setObjectName(QStringLiteral("label_gpsB"));
        label_gpsB->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_gpsB, 10, 1, 1, 1);

        label_childrenB = new QLabel(scrollAreaWidgetContents);
        label_childrenB->setObjectName(QStringLiteral("label_childrenB"));
        label_childrenB->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_childrenB, 1, 1, 1, 1);

        label_childrenA_5 = new QLabel(scrollAreaWidgetContents);
        label_childrenA_5->setObjectName(QStringLiteral("label_childrenA_5"));

        gridLayout_2->addWidget(label_childrenA_5, 3, 0, 1, 1);

        label_labelB = new QLabel(scrollAreaWidgetContents);
        label_labelB->setObjectName(QStringLiteral("label_labelB"));
        label_labelB->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_labelB, 3, 1, 1, 1);

        label_weightB = new QLabel(scrollAreaWidgetContents);
        label_weightB->setObjectName(QStringLiteral("label_weightB"));
        label_weightB->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_weightB, 2, 1, 1, 1);

        label_childrenA_11 = new QLabel(scrollAreaWidgetContents);
        label_childrenA_11->setObjectName(QStringLiteral("label_childrenA_11"));

        gridLayout_2->addWidget(label_childrenA_11, 4, 0, 1, 1);

        label_childrenA_13 = new QLabel(scrollAreaWidgetContents);
        label_childrenA_13->setObjectName(QStringLiteral("label_childrenA_13"));

        gridLayout_2->addWidget(label_childrenA_13, 5, 0, 1, 1);

        label_parentsB = new QLabel(scrollAreaWidgetContents);
        label_parentsB->setObjectName(QStringLiteral("label_parentsB"));
        label_parentsB->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_parentsB, 0, 1, 1, 1);

        label_parentsA_4 = new QLabel(scrollAreaWidgetContents);
        label_parentsA_4->setObjectName(QStringLiteral("label_parentsA_4"));

        gridLayout_2->addWidget(label_parentsA_4, 0, 0, 1, 1);

        label_childrenA_3 = new QLabel(scrollAreaWidgetContents);
        label_childrenA_3->setObjectName(QStringLiteral("label_childrenA_3"));

        gridLayout_2->addWidget(label_childrenA_3, 1, 0, 1, 1);

        label_childrenA_7 = new QLabel(scrollAreaWidgetContents);
        label_childrenA_7->setObjectName(QStringLiteral("label_childrenA_7"));

        gridLayout_2->addWidget(label_childrenA_7, 7, 0, 1, 1);

        label_stampB = new QLabel(scrollAreaWidgetContents);
        label_stampB->setObjectName(QStringLiteral("label_stampB"));
        label_stampB->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_stampB, 7, 1, 1, 1);

        label_childrenA_19 = new QLabel(scrollAreaWidgetContents);
        label_childrenA_19->setObjectName(QStringLiteral("label_childrenA_19"));

        gridLayout_2->addWidget(label_childrenA_19, 6, 0, 1, 1);

        label_velB = new QLabel(scrollAreaWidgetContents);
        label_velB->setObjectName(QStringLiteral("label_velB"));
        label_velB->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_velB, 6, 1, 1, 1);

        label_childrenA_21 = new QLabel(scrollAreaWidgetContents);
        label_childrenA_21->setObjectName(QStringLiteral("label_childrenA_21"));

        gridLayout_2->addWidget(label_childrenA_21, 11, 0, 1, 1);

        label_sensorsB = new QLabel(scrollAreaWidgetContents);
        label_sensorsB->setObjectName(QStringLiteral("label_sensorsB"));
        label_sensorsB->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_sensorsB, 11, 1, 1, 1);

        label_childrenA_23 = new QLabel(scrollAreaWidgetContents);
        label_childrenA_23->setObjectName(QStringLiteral("label_childrenA_23"));

        gridLayout_2->addWidget(label_childrenA_23, 9, 0, 1, 1);

        label_scanB = new QLabel(scrollAreaWidgetContents);
        label_scanB->setObjectName(QStringLiteral("label_scanB"));
        label_scanB->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_2->addWidget(label_scanB, 9, 1, 1, 1);

        gridLayout_2->setColumnStretch(1, 1);
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_11->addWidget(scrollArea, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(12, 12, 12, 12);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_4->addWidget(label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_4->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_indexA = new QLabel(centralwidget);
        label_indexA->setObjectName(QStringLiteral("label_indexA"));

        verticalLayout_3->addWidget(label_indexA);

        label_idA = new QLabel(centralwidget);
        label_idA->setObjectName(QStringLiteral("label_idA"));

        verticalLayout_3->addWidget(label_idA);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalSlider_A = new QSlider(centralwidget);
        horizontalSlider_A->setObjectName(QStringLiteral("horizontalSlider_A"));
        horizontalSlider_A->setFocusPolicy(Qt::ClickFocus);
        horizontalSlider_A->setOrientation(Qt::Horizontal);
        horizontalSlider_A->setTickPosition(QSlider::TicksAbove);

        horizontalLayout->addWidget(horizontalSlider_A);


        gridLayout_11->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(12, 12, 12, 12);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_indexB = new QLabel(centralwidget);
        label_indexB->setObjectName(QStringLiteral("label_indexB"));

        verticalLayout_2->addWidget(label_indexB);

        label_idB = new QLabel(centralwidget);
        label_idB->setObjectName(QStringLiteral("label_idB"));

        verticalLayout_2->addWidget(label_idB);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSlider_B = new QSlider(centralwidget);
        horizontalSlider_B->setObjectName(QStringLiteral("horizontalSlider_B"));
        horizontalSlider_B->setFocusPolicy(Qt::ClickFocus);
        horizontalSlider_B->setOrientation(Qt::Horizontal);
        horizontalSlider_B->setTickPosition(QSlider::TicksAbove);

        horizontalLayout_2->addWidget(horizontalSlider_B);


        gridLayout_11->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        gridLayout_11->setRowStretch(0, 1);

        verticalLayout_6->addLayout(gridLayout_11);

        buttonBox = new QDialogButtonBox(centralwidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout_6->addWidget(buttonBox);

        verticalLayout_6->setStretch(0, 1);
        DatabaseViewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DatabaseViewer);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1547, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuExport_poses = new QMenu(menuFile);
        menuExport_poses->setObjectName(QStringLiteral("menuExport_poses"));
        menuExport_GPS = new QMenu(menuFile);
        menuExport_GPS->setObjectName(QStringLiteral("menuExport_GPS"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QStringLiteral("menuView"));
        DatabaseViewer->setMenuBar(menubar);
        dockWidget_constraints = new QDockWidget(DatabaseViewer);
        dockWidget_constraints->setObjectName(QStringLiteral("dockWidget_constraints"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_8 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        layout_constraintsViewer = new QVBoxLayout();
        layout_constraintsViewer->setSpacing(0);
        layout_constraintsViewer->setObjectName(QStringLiteral("layout_constraintsViewer"));

        verticalLayout_8->addLayout(layout_constraintsViewer);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        checkBox_show3DWords = new QCheckBox(dockWidgetContents);
        checkBox_show3DWords->setObjectName(QStringLiteral("checkBox_show3DWords"));

        horizontalLayout_10->addWidget(checkBox_show3DWords);

        checkBox_show3Dclouds = new QCheckBox(dockWidgetContents);
        checkBox_show3Dclouds->setObjectName(QStringLiteral("checkBox_show3Dclouds"));
        checkBox_show3Dclouds->setChecked(true);

        horizontalLayout_10->addWidget(checkBox_show3Dclouds);

        checkBox_show2DScans = new QCheckBox(dockWidgetContents);
        checkBox_show2DScans->setObjectName(QStringLiteral("checkBox_show2DScans"));
        checkBox_show2DScans->setChecked(true);

        horizontalLayout_10->addWidget(checkBox_show2DScans);

        checkBox_odomFrame = new QCheckBox(dockWidgetContents);
        checkBox_odomFrame->setObjectName(QStringLiteral("checkBox_odomFrame"));
        checkBox_odomFrame->setChecked(true);

        horizontalLayout_10->addWidget(checkBox_odomFrame);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);


        verticalLayout_8->addLayout(horizontalLayout_10);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_variance = new QLabel(dockWidgetContents);
        label_variance->setObjectName(QStringLiteral("label_variance"));
        label_variance->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_13->addWidget(label_variance);

        lineEdit_covariance = new QLineEdit(dockWidgetContents);
        lineEdit_covariance->setObjectName(QStringLiteral("lineEdit_covariance"));
        lineEdit_covariance->setReadOnly(true);

        horizontalLayout_13->addWidget(lineEdit_covariance);


        gridLayout_6->addLayout(horizontalLayout_13, 4, 1, 1, 1);

        label = new QLabel(dockWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_6->addWidget(label, 0, 0, 1, 1);

        horizontalSlider_neighbors = new QSlider(dockWidgetContents);
        horizontalSlider_neighbors->setObjectName(QStringLiteral("horizontalSlider_neighbors"));
        horizontalSlider_neighbors->setFocusPolicy(Qt::ClickFocus);
        horizontalSlider_neighbors->setOrientation(Qt::Horizontal);
        horizontalSlider_neighbors->setTickPosition(QSlider::TicksAbove);

        gridLayout_6->addWidget(horizontalSlider_neighbors, 0, 1, 1, 1);

        label_6 = new QLabel(dockWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_6->addWidget(label_6, 1, 0, 1, 1);

        horizontalSlider_loops = new QSlider(dockWidgetContents);
        horizontalSlider_loops->setObjectName(QStringLiteral("horizontalSlider_loops"));
        horizontalSlider_loops->setFocusPolicy(Qt::ClickFocus);
        horizontalSlider_loops->setOrientation(Qt::Horizontal);
        horizontalSlider_loops->setTickPosition(QSlider::TicksAbove);

        gridLayout_6->addWidget(horizontalSlider_loops, 1, 1, 1, 1);

        label_33 = new QLabel(dockWidgetContents);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout_6->addWidget(label_33, 2, 0, 1, 1);

        label_16 = new QLabel(dockWidgetContents);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_6->addWidget(label_16, 3, 0, 1, 1);

        label_constraint = new QLabel(dockWidgetContents);
        label_constraint->setObjectName(QStringLiteral("label_constraint"));
        label_constraint->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(label_constraint, 3, 1, 1, 1);

        checkBox_showOptimized = new QCheckBox(dockWidgetContents);
        checkBox_showOptimized->setObjectName(QStringLiteral("checkBox_showOptimized"));

        gridLayout_6->addWidget(checkBox_showOptimized, 6, 0, 1, 1);

        label_constraint_opt = new QLabel(dockWidgetContents);
        label_constraint_opt->setObjectName(QStringLiteral("label_constraint_opt"));
        label_constraint_opt->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_6->addWidget(label_constraint_opt, 6, 1, 1, 1);

        label_18 = new QLabel(dockWidgetContents);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_6->addWidget(label_18, 4, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_type = new QLabel(dockWidgetContents);
        label_type->setObjectName(QStringLiteral("label_type"));
        label_type->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_14->addWidget(label_type);

        label_type_name = new QLabel(dockWidgetContents);
        label_type_name->setObjectName(QStringLiteral("label_type_name"));
        label_type_name->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_14->addWidget(label_type_name);

        horizontalLayout_14->setStretch(1, 1);

        gridLayout_6->addLayout(horizontalLayout_14, 2, 1, 1, 1);


        verticalLayout_8->addLayout(gridLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_refine = new QPushButton(dockWidgetContents);
        pushButton_refine->setObjectName(QStringLiteral("pushButton_refine"));

        horizontalLayout_5->addWidget(pushButton_refine);

        pushButton_reset = new QPushButton(dockWidgetContents);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));

        horizontalLayout_5->addWidget(pushButton_reset);

        pushButton_add = new QPushButton(dockWidgetContents);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        horizontalLayout_5->addWidget(pushButton_add);

        pushButton_reject = new QPushButton(dockWidgetContents);
        pushButton_reject->setObjectName(QStringLiteral("pushButton_reject"));

        horizontalLayout_5->addWidget(pushButton_reject);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout_8->addLayout(horizontalLayout_5);

        verticalLayout_8->setStretch(0, 1);
        dockWidget_constraints->setWidget(dockWidgetContents);
        DatabaseViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_constraints);
        dockWidget_graphView = new QDockWidget(DatabaseViewer);
        dockWidget_graphView->setObjectName(QStringLiteral("dockWidget_graphView"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout_9 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        graphViewer = new rtabmap::GraphViewer(dockWidgetContents_2);
        graphViewer->setObjectName(QStringLiteral("graphViewer"));

        verticalLayout_9->addWidget(graphViewer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_iterations = new QLabel(dockWidgetContents_2);
        label_iterations->setObjectName(QStringLiteral("label_iterations"));

        horizontalLayout_4->addWidget(label_iterations);

        horizontalSlider_iterations = new QSlider(dockWidgetContents_2);
        horizontalSlider_iterations->setObjectName(QStringLiteral("horizontalSlider_iterations"));
        horizontalSlider_iterations->setFocusPolicy(Qt::ClickFocus);
        horizontalSlider_iterations->setOrientation(Qt::Horizontal);
        horizontalSlider_iterations->setTickPosition(QSlider::TicksAbove);

        horizontalLayout_4->addWidget(horizontalSlider_iterations);

        checkBox_iterativeOptimization = new QCheckBox(dockWidgetContents_2);
        checkBox_iterativeOptimization->setObjectName(QStringLiteral("checkBox_iterativeOptimization"));
        checkBox_iterativeOptimization->setChecked(true);

        horizontalLayout_4->addWidget(checkBox_iterativeOptimization);


        verticalLayout_9->addLayout(horizontalLayout_4);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_loopClosures = new QLabel(dockWidgetContents_2);
        label_loopClosures->setObjectName(QStringLiteral("label_loopClosures"));
        label_loopClosures->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_5->addWidget(label_loopClosures, 9, 0, 1, 1);

        label_timeGrid = new QLabel(dockWidgetContents_2);
        label_timeGrid->setObjectName(QStringLiteral("label_timeGrid"));
        label_timeGrid->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_5->addWidget(label_timeGrid, 6, 0, 1, 1);

        label_timeOptimization = new QLabel(dockWidgetContents_2);
        label_timeOptimization->setObjectName(QStringLiteral("label_timeOptimization"));
        label_timeOptimization->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_5->addWidget(label_timeOptimization, 5, 0, 1, 1);

        spinBox_optimizationsFrom = new QSpinBox(dockWidgetContents_2);
        spinBox_optimizationsFrom->setObjectName(QStringLiteral("spinBox_optimizationsFrom"));

        gridLayout_5->addWidget(spinBox_optimizationsFrom, 0, 0, 1, 1);

        label_52 = new QLabel(dockWidgetContents_2);
        label_52->setObjectName(QStringLiteral("label_52"));

        gridLayout_5->addWidget(label_52, 8, 1, 1, 1);

        label_39 = new QLabel(dockWidgetContents_2);
        label_39->setObjectName(QStringLiteral("label_39"));

        gridLayout_5->addWidget(label_39, 5, 1, 1, 1);

        label_41 = new QLabel(dockWidgetContents_2);
        label_41->setObjectName(QStringLiteral("label_41"));

        gridLayout_5->addWidget(label_41, 9, 1, 1, 1);

        label_10 = new QLabel(dockWidgetContents_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_5->addWidget(label_10, 4, 1, 1, 1);

        label_45 = new QLabel(dockWidgetContents_2);
        label_45->setObjectName(QStringLiteral("label_45"));

        gridLayout_5->addWidget(label_45, 6, 1, 1, 1);

        label_pathLength = new QLabel(dockWidgetContents_2);
        label_pathLength->setObjectName(QStringLiteral("label_pathLength"));
        label_pathLength->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_5->addWidget(label_pathLength, 4, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_optimizeFrom = new QLabel(dockWidgetContents_2);
        label_optimizeFrom->setObjectName(QStringLiteral("label_optimizeFrom"));

        horizontalLayout_7->addWidget(label_optimizeFrom);

        checkBox_spanAllMaps = new QCheckBox(dockWidgetContents_2);
        checkBox_spanAllMaps->setObjectName(QStringLiteral("checkBox_spanAllMaps"));
        checkBox_spanAllMaps->setChecked(true);

        horizontalLayout_7->addWidget(checkBox_spanAllMaps);

        checkBox_wmState = new QCheckBox(dockWidgetContents_2);
        checkBox_wmState->setObjectName(QStringLiteral("checkBox_wmState"));

        horizontalLayout_7->addWidget(checkBox_wmState);

        horizontalLayout_7->setStretch(2, 1);

        gridLayout_5->addLayout(horizontalLayout_7, 0, 1, 1, 1);

        label_poses = new QLabel(dockWidgetContents_2);
        label_poses->setObjectName(QStringLiteral("label_poses"));
        label_poses->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_5->addWidget(label_poses, 8, 0, 1, 1);

        label_alignPosesWithGroundTruth = new QLabel(dockWidgetContents_2);
        label_alignPosesWithGroundTruth->setObjectName(QStringLiteral("label_alignPosesWithGroundTruth"));
        label_alignPosesWithGroundTruth->setWordWrap(true);

        gridLayout_5->addWidget(label_alignPosesWithGroundTruth, 1, 1, 1, 1);

        checkBox_ignoreIntermediateNodes = new QCheckBox(dockWidgetContents_2);
        checkBox_ignoreIntermediateNodes->setObjectName(QStringLiteral("checkBox_ignoreIntermediateNodes"));
        checkBox_ignoreIntermediateNodes->setChecked(false);

        gridLayout_5->addWidget(checkBox_ignoreIntermediateNodes, 3, 0, 1, 1);

        checkBox_alignPosesWithGroundTruth = new QCheckBox(dockWidgetContents_2);
        checkBox_alignPosesWithGroundTruth->setObjectName(QStringLiteral("checkBox_alignPosesWithGroundTruth"));
        checkBox_alignPosesWithGroundTruth->setChecked(true);

        gridLayout_5->addWidget(checkBox_alignPosesWithGroundTruth, 1, 0, 1, 1);

        label_rmse = new QLabel(dockWidgetContents_2);
        label_rmse->setObjectName(QStringLiteral("label_rmse"));
        label_rmse->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayout_5->addWidget(label_rmse, 7, 0, 1, 1);

        label_ignoreINtermediateNdoes = new QLabel(dockWidgetContents_2);
        label_ignoreINtermediateNdoes->setObjectName(QStringLiteral("label_ignoreINtermediateNdoes"));
        label_ignoreINtermediateNdoes->setWordWrap(true);

        gridLayout_5->addWidget(label_ignoreINtermediateNdoes, 3, 1, 1, 1);

        label_rmse_title = new QLabel(dockWidgetContents_2);
        label_rmse_title->setObjectName(QStringLiteral("label_rmse_title"));

        gridLayout_5->addWidget(label_rmse_title, 7, 1, 1, 1);

        label_alignScansCloudsWithGroundTruth = new QLabel(dockWidgetContents_2);
        label_alignScansCloudsWithGroundTruth->setObjectName(QStringLiteral("label_alignScansCloudsWithGroundTruth"));
        label_alignScansCloudsWithGroundTruth->setWordWrap(true);

        gridLayout_5->addWidget(label_alignScansCloudsWithGroundTruth, 2, 1, 1, 1);

        checkBox_alignScansCloudsWithGroundTruth = new QCheckBox(dockWidgetContents_2);
        checkBox_alignScansCloudsWithGroundTruth->setObjectName(QStringLiteral("checkBox_alignScansCloudsWithGroundTruth"));
        checkBox_alignScansCloudsWithGroundTruth->setChecked(true);

        gridLayout_5->addWidget(checkBox_alignScansCloudsWithGroundTruth, 2, 0, 1, 1);

        gridLayout_5->setColumnStretch(1, 1);

        verticalLayout_9->addLayout(gridLayout_5);

        dockWidget_graphView->setWidget(dockWidgetContents_2);
        DatabaseViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_graphView);
        dockWidget_guiparameters = new QDockWidget(DatabaseViewer);
        dockWidget_guiparameters->setObjectName(QStringLiteral("dockWidget_guiparameters"));
        dockWidget_guiparameters->setFloating(false);
        dockWidget_guiparameters->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        verticalLayout_10 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        comboBox_logger_level = new QComboBox(dockWidgetContents_3);
        comboBox_logger_level->setObjectName(QStringLiteral("comboBox_logger_level"));

        gridLayout_4->addWidget(comboBox_logger_level, 0, 0, 1, 1);

        label_logger_level = new QLabel(dockWidgetContents_3);
        label_logger_level->setObjectName(QStringLiteral("label_logger_level"));
        label_logger_level->setWordWrap(true);

        gridLayout_4->addWidget(label_logger_level, 0, 1, 1, 1);

        gridLayout_4->setColumnStretch(1, 1);

        verticalLayout_10->addLayout(gridLayout_4);

        toolBox = new QToolBox(dockWidgetContents_3);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 318, 165));
        gridLayout_7 = new QGridLayout(page_3);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        checkBox_ignoreGlobalLoop = new QCheckBox(page_3);
        checkBox_ignoreGlobalLoop->setObjectName(QStringLiteral("checkBox_ignoreGlobalLoop"));
        checkBox_ignoreGlobalLoop->setChecked(false);

        gridLayout_7->addWidget(checkBox_ignoreGlobalLoop, 2, 0, 1, 1);

        label_49 = new QLabel(page_3);
        label_49->setObjectName(QStringLiteral("label_49"));

        gridLayout_7->addWidget(label_49, 4, 2, 1, 1);

        checkBox_ignoreLocalLoopSpace = new QCheckBox(page_3);
        checkBox_ignoreLocalLoopSpace->setObjectName(QStringLiteral("checkBox_ignoreLocalLoopSpace"));
        checkBox_ignoreLocalLoopSpace->setChecked(false);

        gridLayout_7->addWidget(checkBox_ignoreLocalLoopSpace, 3, 0, 1, 1);

        label_48 = new QLabel(page_3);
        label_48->setObjectName(QStringLiteral("label_48"));

        gridLayout_7->addWidget(label_48, 2, 2, 1, 1);

        label_35 = new QLabel(page_3);
        label_35->setObjectName(QStringLiteral("label_35"));

        gridLayout_7->addWidget(label_35, 1, 2, 1, 1);

        checkBox_ignorePoseCorrection = new QCheckBox(page_3);
        checkBox_ignorePoseCorrection->setObjectName(QStringLiteral("checkBox_ignorePoseCorrection"));
        checkBox_ignorePoseCorrection->setChecked(false);

        gridLayout_7->addWidget(checkBox_ignorePoseCorrection, 1, 0, 1, 1);

        checkBox_ignoreLocalLoopTime = new QCheckBox(page_3);
        checkBox_ignoreLocalLoopTime->setObjectName(QStringLiteral("checkBox_ignoreLocalLoopTime"));
        checkBox_ignoreLocalLoopTime->setChecked(false);

        gridLayout_7->addWidget(checkBox_ignoreLocalLoopTime, 4, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(0, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_3, 6, 0, 1, 1);

        checkBox_ignoreUserLoop = new QCheckBox(page_3);
        checkBox_ignoreUserLoop->setObjectName(QStringLiteral("checkBox_ignoreUserLoop"));
        checkBox_ignoreUserLoop->setChecked(false);

        gridLayout_7->addWidget(checkBox_ignoreUserLoop, 5, 0, 1, 1);

        label_50 = new QLabel(page_3);
        label_50->setObjectName(QStringLiteral("label_50"));

        gridLayout_7->addWidget(label_50, 5, 2, 1, 1);

        label_47 = new QLabel(page_3);
        label_47->setObjectName(QStringLiteral("label_47"));

        gridLayout_7->addWidget(label_47, 3, 2, 1, 1);

        label_scale_title = new QLabel(page_3);
        label_scale_title->setObjectName(QStringLiteral("label_scale_title"));

        gridLayout_7->addWidget(label_scale_title, 0, 2, 1, 1);

        doubleSpinBox_optimizationScale = new QDoubleSpinBox(page_3);
        doubleSpinBox_optimizationScale->setObjectName(QStringLiteral("doubleSpinBox_optimizationScale"));
        doubleSpinBox_optimizationScale->setDecimals(3);
        doubleSpinBox_optimizationScale->setMinimum(0.1);
        doubleSpinBox_optimizationScale->setMaximum(9.9);
        doubleSpinBox_optimizationScale->setSingleStep(0.001);
        doubleSpinBox_optimizationScale->setValue(1);

        gridLayout_7->addWidget(doubleSpinBox_optimizationScale, 0, 0, 1, 1);

        toolBox->addItem(page_3, QStringLiteral("Graph optimization"));
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        page_4->setGeometry(QRect(0, 0, 280, 875));
        verticalLayout_16 = new QVBoxLayout(page_4);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label_51 = new QLabel(page_4);
        label_51->setObjectName(QStringLiteral("label_51"));
        label_51->setWordWrap(true);

        gridLayout_9->addWidget(label_51, 10, 1, 1, 1);

        doubleSpinBox_gainCompensationRadius = new QDoubleSpinBox(page_4);
        doubleSpinBox_gainCompensationRadius->setObjectName(QStringLiteral("doubleSpinBox_gainCompensationRadius"));
        doubleSpinBox_gainCompensationRadius->setDecimals(2);
        doubleSpinBox_gainCompensationRadius->setMinimum(0);
        doubleSpinBox_gainCompensationRadius->setMaximum(10);
        doubleSpinBox_gainCompensationRadius->setSingleStep(0.01);
        doubleSpinBox_gainCompensationRadius->setValue(0);

        gridLayout_9->addWidget(doubleSpinBox_gainCompensationRadius, 10, 0, 1, 1);

        label_53 = new QLabel(page_4);
        label_53->setObjectName(QStringLiteral("label_53"));

        gridLayout_9->addWidget(label_53, 4, 1, 1, 1);

        label_54 = new QLabel(page_4);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setWordWrap(true);

        gridLayout_9->addWidget(label_54, 12, 1, 1, 1);

        checkBox_octomap = new QCheckBox(page_4);
        checkBox_octomap->setObjectName(QStringLiteral("checkBox_octomap"));

        gridLayout_9->addWidget(checkBox_octomap, 4, 0, 1, 1);

        checkBox_grid_regenerateFromSavedGrid = new QCheckBox(page_4);
        checkBox_grid_regenerateFromSavedGrid->setObjectName(QStringLiteral("checkBox_grid_regenerateFromSavedGrid"));
        checkBox_grid_regenerateFromSavedGrid->setChecked(false);

        gridLayout_9->addWidget(checkBox_grid_regenerateFromSavedGrid, 9, 0, 1, 1);

        doubleSpinBox_voxelSize = new QDoubleSpinBox(page_4);
        doubleSpinBox_voxelSize->setObjectName(QStringLiteral("doubleSpinBox_voxelSize"));
        doubleSpinBox_voxelSize->setDecimals(3);
        doubleSpinBox_voxelSize->setMinimum(0);
        doubleSpinBox_voxelSize->setMaximum(99);
        doubleSpinBox_voxelSize->setSingleStep(0.01);
        doubleSpinBox_voxelSize->setValue(0);

        gridLayout_9->addWidget(doubleSpinBox_voxelSize, 12, 0, 1, 1);

        spinBox_grid_depth = new QSpinBox(page_4);
        spinBox_grid_depth->setObjectName(QStringLiteral("spinBox_grid_depth"));
        spinBox_grid_depth->setMinimum(0);
        spinBox_grid_depth->setMaximum(16);
        spinBox_grid_depth->setValue(16);

        gridLayout_9->addWidget(spinBox_grid_depth, 8, 0, 1, 1);

        checkBox_grid_empty = new QCheckBox(page_4);
        checkBox_grid_empty->setObjectName(QStringLiteral("checkBox_grid_empty"));
        checkBox_grid_empty->setChecked(true);

        gridLayout_9->addWidget(checkBox_grid_empty, 0, 0, 1, 1);

        label_octomap_cubes = new QLabel(page_4);
        label_octomap_cubes->setObjectName(QStringLiteral("label_octomap_cubes"));
        label_octomap_cubes->setWordWrap(true);

        gridLayout_9->addWidget(label_octomap_cubes, 7, 1, 1, 1);

        comboBox_octomap_rendering_type = new QComboBox(page_4);
        comboBox_octomap_rendering_type->setObjectName(QStringLiteral("comboBox_octomap_rendering_type"));

        gridLayout_9->addWidget(comboBox_octomap_rendering_type, 7, 0, 1, 1);

        label_octomap_depth = new QLabel(page_4);
        label_octomap_depth->setObjectName(QStringLiteral("label_octomap_depth"));
        label_octomap_depth->setWordWrap(true);

        gridLayout_9->addWidget(label_octomap_depth, 8, 1, 1, 1);

        label_55 = new QLabel(page_4);
        label_55->setObjectName(QStringLiteral("label_55"));
        label_55->setWordWrap(true);

        gridLayout_9->addWidget(label_55, 9, 1, 1, 1);

        label_octomap_empty = new QLabel(page_4);
        label_octomap_empty->setObjectName(QStringLiteral("label_octomap_empty"));
        label_octomap_empty->setWordWrap(true);

        gridLayout_9->addWidget(label_octomap_empty, 0, 1, 1, 1);

        label_octomap_empty_3 = new QLabel(page_4);
        label_octomap_empty_3->setObjectName(QStringLiteral("label_octomap_empty_3"));
        label_octomap_empty_3->setWordWrap(true);

        gridLayout_9->addWidget(label_octomap_empty_3, 2, 1, 1, 1);

        label_octomap_empty_2 = new QLabel(page_4);
        label_octomap_empty_2->setObjectName(QStringLiteral("label_octomap_empty_2"));
        label_octomap_empty_2->setWordWrap(true);

        gridLayout_9->addWidget(label_octomap_empty_2, 1, 1, 1, 1);

        label_octomap_empty_4 = new QLabel(page_4);
        label_octomap_empty_4->setObjectName(QStringLiteral("label_octomap_empty_4"));
        label_octomap_empty_4->setWordWrap(true);

        gridLayout_9->addWidget(label_octomap_empty_4, 3, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        toolButton_groundColor = new QToolButton(page_4);
        toolButton_groundColor->setObjectName(QStringLiteral("toolButton_groundColor"));

        horizontalLayout_9->addWidget(toolButton_groundColor);

        lineEdit_groundColor = new QLineEdit(page_4);
        lineEdit_groundColor->setObjectName(QStringLiteral("lineEdit_groundColor"));
        lineEdit_groundColor->setReadOnly(true);

        horizontalLayout_9->addWidget(lineEdit_groundColor);


        gridLayout_9->addLayout(horizontalLayout_9, 2, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        toolButton_obstacleColor = new QToolButton(page_4);
        toolButton_obstacleColor->setObjectName(QStringLiteral("toolButton_obstacleColor"));

        horizontalLayout_11->addWidget(toolButton_obstacleColor);

        lineEdit_obstacleColor = new QLineEdit(page_4);
        lineEdit_obstacleColor->setObjectName(QStringLiteral("lineEdit_obstacleColor"));
        lineEdit_obstacleColor->setReadOnly(true);

        horizontalLayout_11->addWidget(lineEdit_obstacleColor);


        gridLayout_9->addLayout(horizontalLayout_11, 1, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        toolButton_emptyColor = new QToolButton(page_4);
        toolButton_emptyColor->setObjectName(QStringLiteral("toolButton_emptyColor"));

        horizontalLayout_12->addWidget(toolButton_emptyColor);

        lineEdit_emptyColor = new QLineEdit(page_4);
        lineEdit_emptyColor->setObjectName(QStringLiteral("lineEdit_emptyColor"));
        lineEdit_emptyColor->setReadOnly(true);

        horizontalLayout_12->addWidget(lineEdit_emptyColor);


        gridLayout_9->addLayout(horizontalLayout_12, 3, 0, 1, 1);

        label_56 = new QLabel(page_4);
        label_56->setObjectName(QStringLiteral("label_56"));
        label_56->setWordWrap(true);

        gridLayout_9->addWidget(label_56, 11, 1, 1, 1);

        spinBox_decimation = new QSpinBox(page_4);
        spinBox_decimation->setObjectName(QStringLiteral("spinBox_decimation"));
        spinBox_decimation->setMinimum(1);
        spinBox_decimation->setMaximum(16);
        spinBox_decimation->setValue(16);

        gridLayout_9->addWidget(spinBox_decimation, 11, 0, 1, 1);


        verticalLayout_16->addLayout(gridLayout_9);

        groupBox_posefiltering = new QGroupBox(page_4);
        groupBox_posefiltering->setObjectName(QStringLiteral("groupBox_posefiltering"));
        groupBox_posefiltering->setCheckable(true);
        groupBox_posefiltering->setChecked(false);
        gridLayout_12 = new QGridLayout(groupBox_posefiltering);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        doubleSpinBox_posefilteringAngle = new QDoubleSpinBox(groupBox_posefiltering);
        doubleSpinBox_posefilteringAngle->setObjectName(QStringLiteral("doubleSpinBox_posefilteringAngle"));
        doubleSpinBox_posefilteringAngle->setDecimals(0);
        doubleSpinBox_posefilteringAngle->setMaximum(180);
        doubleSpinBox_posefilteringAngle->setValue(30);

        gridLayout_12->addWidget(doubleSpinBox_posefilteringAngle, 4, 0, 1, 1);

        doubleSpinBox_posefilteringRadius = new QDoubleSpinBox(groupBox_posefiltering);
        doubleSpinBox_posefilteringRadius->setObjectName(QStringLiteral("doubleSpinBox_posefilteringRadius"));
        doubleSpinBox_posefilteringRadius->setMinimum(0.01);
        doubleSpinBox_posefilteringRadius->setValue(0.1);

        gridLayout_12->addWidget(doubleSpinBox_posefilteringRadius, 3, 0, 1, 1);

        label_42 = new QLabel(groupBox_posefiltering);
        label_42->setObjectName(QStringLiteral("label_42"));

        gridLayout_12->addWidget(label_42, 3, 1, 1, 1);

        label_43 = new QLabel(groupBox_posefiltering);
        label_43->setObjectName(QStringLiteral("label_43"));

        gridLayout_12->addWidget(label_43, 4, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_4, 5, 0, 1, 1);

        gridLayout_12->setColumnStretch(1, 1);

        verticalLayout_16->addWidget(groupBox_posefiltering);

        groupBox = new QGroupBox(page_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_13 = new QGridLayout(groupBox);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_13->addWidget(label_14, 3, 1, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_13->addWidget(label_12, 0, 1, 1, 1);

        spinBox_mesh_angleTolerance = new QSpinBox(groupBox);
        spinBox_mesh_angleTolerance->setObjectName(QStringLiteral("spinBox_mesh_angleTolerance"));
        spinBox_mesh_angleTolerance->setMinimum(1);
        spinBox_mesh_angleTolerance->setMaximum(180);
        spinBox_mesh_angleTolerance->setValue(15);

        gridLayout_13->addWidget(spinBox_mesh_angleTolerance, 0, 0, 1, 1);

        spinBox_mesh_triangleSize = new QSpinBox(groupBox);
        spinBox_mesh_triangleSize->setObjectName(QStringLiteral("spinBox_mesh_triangleSize"));
        spinBox_mesh_triangleSize->setMinimum(2);
        spinBox_mesh_triangleSize->setMaximum(99);

        gridLayout_13->addWidget(spinBox_mesh_triangleSize, 3, 0, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_13->addWidget(label_13, 2, 1, 1, 1);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_13->addWidget(label_17, 5, 1, 1, 1);

        spinBox_mesh_depthError = new QSpinBox(groupBox);
        spinBox_mesh_depthError->setObjectName(QStringLiteral("spinBox_mesh_depthError"));
        spinBox_mesh_depthError->setMinimum(1);
        spinBox_mesh_depthError->setValue(10);

        gridLayout_13->addWidget(spinBox_mesh_depthError, 5, 0, 1, 1);

        checkBox_mesh_quad = new QCheckBox(groupBox);
        checkBox_mesh_quad->setObjectName(QStringLiteral("checkBox_mesh_quad"));
        checkBox_mesh_quad->setChecked(true);

        gridLayout_13->addWidget(checkBox_mesh_quad, 2, 0, 1, 1);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_13->addWidget(label_15, 4, 1, 1, 1);

        spinBox_mesh_fillDepthHoles = new QSpinBox(groupBox);
        spinBox_mesh_fillDepthHoles->setObjectName(QStringLiteral("spinBox_mesh_fillDepthHoles"));
        spinBox_mesh_fillDepthHoles->setMinimum(0);
        spinBox_mesh_fillDepthHoles->setMaximum(99);
        spinBox_mesh_fillDepthHoles->setValue(0);

        gridLayout_13->addWidget(spinBox_mesh_fillDepthHoles, 4, 0, 1, 1);

        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_13->addWidget(label_20, 1, 1, 1, 1);

        spinBox_mesh_minClusterSize = new QSpinBox(groupBox);
        spinBox_mesh_minClusterSize->setObjectName(QStringLiteral("spinBox_mesh_minClusterSize"));
        spinBox_mesh_minClusterSize->setMinimum(0);
        spinBox_mesh_minClusterSize->setMaximum(999);
        spinBox_mesh_minClusterSize->setValue(0);

        gridLayout_13->addWidget(spinBox_mesh_minClusterSize, 1, 0, 1, 1);


        verticalLayout_16->addWidget(groupBox);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_6);

        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_2);

        toolBox->addItem(page_4, QStringLiteral("Grid/cloud generation"));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        page_5->setGeometry(QRect(0, 0, 226, 160));
        gridLayout_10 = new QGridLayout(page_5);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        label_32 = new QLabel(page_5);
        label_32->setObjectName(QStringLiteral("label_32"));

        gridLayout_10->addWidget(label_32, 3, 1, 1, 1);

        doubleSpinBox_detectMore_radius = new QDoubleSpinBox(page_5);
        doubleSpinBox_detectMore_radius->setObjectName(QStringLiteral("doubleSpinBox_detectMore_radius"));
        doubleSpinBox_detectMore_radius->setDecimals(2);
        doubleSpinBox_detectMore_radius->setMaximum(10);
        doubleSpinBox_detectMore_radius->setSingleStep(0.1);
        doubleSpinBox_detectMore_radius->setValue(1);

        gridLayout_10->addWidget(doubleSpinBox_detectMore_radius, 0, 0, 1, 1);

        label_29 = new QLabel(page_5);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_10->addWidget(label_29, 0, 1, 1, 1);

        doubleSpinBox_detectMore_angle = new QDoubleSpinBox(page_5);
        doubleSpinBox_detectMore_angle->setObjectName(QStringLiteral("doubleSpinBox_detectMore_angle"));
        doubleSpinBox_detectMore_angle->setDecimals(0);
        doubleSpinBox_detectMore_angle->setMaximum(180);
        doubleSpinBox_detectMore_angle->setSingleStep(1);
        doubleSpinBox_detectMore_angle->setValue(30);

        gridLayout_10->addWidget(doubleSpinBox_detectMore_angle, 1, 0, 1, 1);

        label_30 = new QLabel(page_5);
        label_30->setObjectName(QStringLiteral("label_30"));

        gridLayout_10->addWidget(label_30, 1, 1, 1, 1);

        spinBox_detectMore_iterations = new QSpinBox(page_5);
        spinBox_detectMore_iterations->setObjectName(QStringLiteral("spinBox_detectMore_iterations"));
        spinBox_detectMore_iterations->setMinimum(1);
        spinBox_detectMore_iterations->setMaximum(100);
        spinBox_detectMore_iterations->setValue(5);

        gridLayout_10->addWidget(spinBox_detectMore_iterations, 2, 0, 1, 1);

        label_31 = new QLabel(page_5);
        label_31->setObjectName(QStringLiteral("label_31"));

        gridLayout_10->addWidget(label_31, 2, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_10->addItem(verticalSpacer_5, 5, 0, 1, 1);

        label_34 = new QLabel(page_5);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout_10->addWidget(label_34, 4, 1, 1, 1);

        checkBox_detectMore_intraSession = new QCheckBox(page_5);
        checkBox_detectMore_intraSession->setObjectName(QStringLiteral("checkBox_detectMore_intraSession"));

        gridLayout_10->addWidget(checkBox_detectMore_intraSession, 3, 0, 1, 1);

        checkBox_detectMore_interSession = new QCheckBox(page_5);
        checkBox_detectMore_interSession->setObjectName(QStringLiteral("checkBox_detectMore_interSession"));

        gridLayout_10->addWidget(checkBox_detectMore_interSession, 4, 0, 1, 1);

        gridLayout_10->setColumnStretch(1, 1);
        toolBox->addItem(page_5, QStringLiteral("Detect more loop closures"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 185, 485));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        spinBox_icp_decimation = new QSpinBox(page_2);
        spinBox_icp_decimation->setObjectName(QStringLiteral("spinBox_icp_decimation"));
        spinBox_icp_decimation->setMinimum(-32);
        spinBox_icp_decimation->setMaximum(32);

        gridLayout_3->addWidget(spinBox_icp_decimation, 1, 0, 1, 1);

        label_9 = new QLabel(page_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setWordWrap(true);

        gridLayout_3->addWidget(label_9, 1, 2, 1, 1);

        doubleSpinBox_icp_maxDepth = new QDoubleSpinBox(page_2);
        doubleSpinBox_icp_maxDepth->setObjectName(QStringLiteral("doubleSpinBox_icp_maxDepth"));

        gridLayout_3->addWidget(doubleSpinBox_icp_maxDepth, 2, 0, 1, 2);

        label_11 = new QLabel(page_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setWordWrap(true);

        gridLayout_3->addWidget(label_11, 2, 2, 1, 1);

        checkBox_icp_from_depth = new QCheckBox(page_2);
        checkBox_icp_from_depth->setObjectName(QStringLiteral("checkBox_icp_from_depth"));

        gridLayout_3->addWidget(checkBox_icp_from_depth, 0, 0, 1, 1);

        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setWordWrap(true);

        gridLayout_3->addWidget(label_7, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 4, 0, 1, 1);

        label_19 = new QLabel(page_2);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setWordWrap(true);

        gridLayout_3->addWidget(label_19, 3, 2, 1, 1);

        doubleSpinBox_icp_minDepth = new QDoubleSpinBox(page_2);
        doubleSpinBox_icp_minDepth->setObjectName(QStringLiteral("doubleSpinBox_icp_minDepth"));

        gridLayout_3->addWidget(doubleSpinBox_icp_minDepth, 3, 0, 1, 1);

        gridLayout_3->setColumnStretch(2, 1);
        toolBox->addItem(page_2, QStringLiteral("Refine"));

        verticalLayout_10->addWidget(toolBox);

        dockWidget_guiparameters->setWidget(dockWidgetContents_3);
        DatabaseViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_guiparameters);
        dockWidget_stereoView = new QDockWidget(DatabaseViewer);
        dockWidget_stereoView->setObjectName(QStringLiteral("dockWidget_stereoView"));
        dockWidgetContents_stereo = new QWidget();
        dockWidgetContents_stereo->setObjectName(QStringLiteral("dockWidgetContents_stereo"));
        verticalLayout_11 = new QVBoxLayout(dockWidgetContents_stereo);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_stereo = new QHBoxLayout();
        horizontalLayout_stereo->setObjectName(QStringLiteral("horizontalLayout_stereo"));
        graphicsView_stereo = new rtabmap::ImageView(dockWidgetContents_stereo);
        graphicsView_stereo->setObjectName(QStringLiteral("graphicsView_stereo"));

        horizontalLayout_stereo->addWidget(graphicsView_stereo);

        horizontalLayout_stereo->setStretch(0, 1);

        verticalLayout_11->addLayout(horizontalLayout_stereo);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_stereo_inliers_name = new QLabel(dockWidgetContents_stereo);
        label_stereo_inliers_name->setObjectName(QStringLiteral("label_stereo_inliers_name"));
        label_stereo_inliers_name->setTextFormat(Qt::RichText);

        horizontalLayout_6->addWidget(label_stereo_inliers_name);

        label_stereo_inliers = new QLabel(dockWidgetContents_stereo);
        label_stereo_inliers->setObjectName(QStringLiteral("label_stereo_inliers"));

        horizontalLayout_6->addWidget(label_stereo_inliers);

        label_stereo_slopeOutliers_name = new QLabel(dockWidgetContents_stereo);
        label_stereo_slopeOutliers_name->setObjectName(QStringLiteral("label_stereo_slopeOutliers_name"));
        label_stereo_slopeOutliers_name->setTextFormat(Qt::RichText);

        horizontalLayout_6->addWidget(label_stereo_slopeOutliers_name);

        label_stereo_slopeOutliers = new QLabel(dockWidgetContents_stereo);
        label_stereo_slopeOutliers->setObjectName(QStringLiteral("label_stereo_slopeOutliers"));

        horizontalLayout_6->addWidget(label_stereo_slopeOutliers);

        label_stereo_disparityOutliers_name = new QLabel(dockWidgetContents_stereo);
        label_stereo_disparityOutliers_name->setObjectName(QStringLiteral("label_stereo_disparityOutliers_name"));
        label_stereo_disparityOutliers_name->setTextFormat(Qt::RichText);

        horizontalLayout_6->addWidget(label_stereo_disparityOutliers_name);

        label_stereo_disparityOutliers = new QLabel(dockWidgetContents_stereo);
        label_stereo_disparityOutliers->setObjectName(QStringLiteral("label_stereo_disparityOutliers"));

        horizontalLayout_6->addWidget(label_stereo_disparityOutliers);

        label_stereo_flowOutliers_name = new QLabel(dockWidgetContents_stereo);
        label_stereo_flowOutliers_name->setObjectName(QStringLiteral("label_stereo_flowOutliers_name"));
        label_stereo_flowOutliers_name->setTextFormat(Qt::RichText);

        horizontalLayout_6->addWidget(label_stereo_flowOutliers_name);

        label_stereo_flowOutliers = new QLabel(dockWidgetContents_stereo);
        label_stereo_flowOutliers->setObjectName(QStringLiteral("label_stereo_flowOutliers"));

        horizontalLayout_6->addWidget(label_stereo_flowOutliers);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout_11->addLayout(horizontalLayout_6);

        verticalLayout_11->setStretch(0, 1);
        dockWidget_stereoView->setWidget(dockWidgetContents_stereo);
        DatabaseViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(4), dockWidget_stereoView);
        dockWidget_view3d = new QDockWidget(DatabaseViewer);
        dockWidget_view3d->setObjectName(QStringLiteral("dockWidget_view3d"));
        dockWidgetContents_3dviews = new QWidget();
        dockWidgetContents_3dviews->setObjectName(QStringLiteral("dockWidgetContents_3dviews"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_3dviews);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3dviews = new QHBoxLayout();
        horizontalLayout_3dviews->setSpacing(1);
        horizontalLayout_3dviews->setObjectName(QStringLiteral("horizontalLayout_3dviews"));

        verticalLayout_5->addLayout(horizontalLayout_3dviews);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkBox_showWords = new QCheckBox(dockWidgetContents_3dviews);
        checkBox_showWords->setObjectName(QStringLiteral("checkBox_showWords"));
        checkBox_showWords->setChecked(false);

        horizontalLayout_3->addWidget(checkBox_showWords);

        checkBox_showCloud = new QCheckBox(dockWidgetContents_3dviews);
        checkBox_showCloud->setObjectName(QStringLiteral("checkBox_showCloud"));
        checkBox_showCloud->setChecked(true);

        horizontalLayout_3->addWidget(checkBox_showCloud);

        checkBox_showMesh = new QCheckBox(dockWidgetContents_3dviews);
        checkBox_showMesh->setObjectName(QStringLiteral("checkBox_showMesh"));
        checkBox_showMesh->setChecked(false);

        horizontalLayout_3->addWidget(checkBox_showMesh);

        checkBox_showScan = new QCheckBox(dockWidgetContents_3dviews);
        checkBox_showScan->setObjectName(QStringLiteral("checkBox_showScan"));
        checkBox_showScan->setChecked(true);

        horizontalLayout_3->addWidget(checkBox_showScan);

        checkBox_showMap = new QCheckBox(dockWidgetContents_3dviews);
        checkBox_showMap->setObjectName(QStringLiteral("checkBox_showMap"));
        checkBox_showMap->setChecked(true);

        horizontalLayout_3->addWidget(checkBox_showMap);

        checkBox_showGrid = new QCheckBox(dockWidgetContents_3dviews);
        checkBox_showGrid->setObjectName(QStringLiteral("checkBox_showGrid"));
        checkBox_showGrid->setChecked(false);

        horizontalLayout_3->addWidget(checkBox_showGrid);

        checkBox_odomFrame_3dview = new QCheckBox(dockWidgetContents_3dviews);
        checkBox_odomFrame_3dview->setObjectName(QStringLiteral("checkBox_odomFrame_3dview"));
        checkBox_odomFrame_3dview->setChecked(true);

        horizontalLayout_3->addWidget(checkBox_odomFrame_3dview);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalLayout_5->setStretch(0, 1);
        dockWidget_view3d->setWidget(dockWidgetContents_3dviews);
        DatabaseViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(4), dockWidget_view3d);
        dockWidget_info = new QDockWidget(DatabaseViewer);
        dockWidget_info->setObjectName(QStringLiteral("dockWidget_info"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        verticalLayout_12 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        textEdit_info = new QTextEdit(dockWidgetContents_4);
        textEdit_info->setObjectName(QStringLiteral("textEdit_info"));
        textEdit_info->setLineWrapMode(QTextEdit::NoWrap);
        textEdit_info->setReadOnly(true);

        verticalLayout_12->addWidget(textEdit_info);

        dockWidget_info->setWidget(dockWidgetContents_4);
        DatabaseViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_info);
        dockWidget_coreparameters = new QDockWidget(DatabaseViewer);
        dockWidget_coreparameters->setObjectName(QStringLiteral("dockWidget_coreparameters"));
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QStringLiteral("dockWidgetContents_7"));
        verticalLayout_13 = new QVBoxLayout(dockWidgetContents_7);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        parameters_toolbox = new rtabmap::ParametersToolBox(dockWidgetContents_7);
        parameters_toolbox->setObjectName(QStringLiteral("parameters_toolbox"));

        verticalLayout_13->addWidget(parameters_toolbox);

        dockWidget_coreparameters->setWidget(dockWidgetContents_7);
        DatabaseViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_coreparameters);
        dockWidget_statistics = new QDockWidget(DatabaseViewer);
        dockWidget_statistics->setObjectName(QStringLiteral("dockWidget_statistics"));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QStringLiteral("dockWidgetContents_5"));
        verticalLayout_7 = new QVBoxLayout(dockWidgetContents_5);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        checkBox_timeStats = new QCheckBox(dockWidgetContents_5);
        checkBox_timeStats->setObjectName(QStringLiteral("checkBox_timeStats"));
        checkBox_timeStats->setChecked(true);

        gridLayout_8->addWidget(checkBox_timeStats, 0, 0, 1, 1);

        label_logger_level_3 = new QLabel(dockWidgetContents_5);
        label_logger_level_3->setObjectName(QStringLiteral("label_logger_level_3"));
        label_logger_level_3->setWordWrap(true);

        gridLayout_8->addWidget(label_logger_level_3, 0, 1, 1, 1);

        gridLayout_8->setColumnStretch(1, 1);

        verticalLayout_7->addLayout(gridLayout_8);

        toolBox_statistics = new rtabmap::StatsToolBox(dockWidgetContents_5);
        toolBox_statistics->setObjectName(QStringLiteral("toolBox_statistics"));

        verticalLayout_7->addWidget(toolBox_statistics);

        dockWidget_statistics->setWidget(dockWidgetContents_5);
        DatabaseViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_statistics);
        dockWidget_occupancyGridView = new QDockWidget(DatabaseViewer);
        dockWidget_occupancyGridView->setObjectName(QStringLiteral("dockWidget_occupancyGridView"));
        dockWidgetContents_occupancyGrid = new QWidget();
        dockWidgetContents_occupancyGrid->setObjectName(QStringLiteral("dockWidgetContents_occupancyGrid"));
        verticalLayout_14 = new QVBoxLayout(dockWidgetContents_occupancyGrid);
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        layout_occupancyGridView = new QVBoxLayout();
        layout_occupancyGridView->setSpacing(0);
        layout_occupancyGridView->setObjectName(QStringLiteral("layout_occupancyGridView"));

        verticalLayout_14->addLayout(layout_occupancyGridView);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        checkBox_grid_2d = new QCheckBox(dockWidgetContents_occupancyGrid);
        checkBox_grid_2d->setObjectName(QStringLiteral("checkBox_grid_2d"));
        checkBox_grid_2d->setChecked(false);

        horizontalLayout_8->addWidget(checkBox_grid_2d);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_14->addLayout(horizontalLayout_8);

        verticalLayout_14->setStretch(0, 1);
        dockWidget_occupancyGridView->setWidget(dockWidgetContents_occupancyGrid);
        DatabaseViewer->addDockWidget(static_cast<Qt::DockWidgetArea>(4), dockWidget_occupancyGridView);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menuFile->addAction(actionOpen_database);
        menuFile->addAction(actionClose_database);
        menuFile->addSeparator();
        menuFile->addAction(actionDatabase_recovery);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_config);
        menuFile->addAction(actionRestore_default_GUI_settings);
        menuFile->addSeparator();
        menuFile->addAction(actionGenerate_3D_map_pcd);
        menuFile->addAction(actionExport);
        menuFile->addAction(actionExtract_images);
        menuFile->addAction(menuExport_poses->menuAction());
        menuFile->addAction(menuExport_GPS->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionEdit_optimized_2D_map);
        menuFile->addAction(actionExport_saved_2D_map);
        menuFile->addAction(actionImport_2D_map);
        menuFile->addAction(actionRegenerate_optimized_2D_map);
        menuFile->addSeparator();
        menuFile->addAction(actionView_optimized_mesh);
        menuFile->addAction(actionUpdate_optimized_mesh);
        menuFile->addAction(actionExport_optimized_mesh);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuExport_poses->addAction(actionRaw_format_txt);
        menuExport_poses->addAction(actionRGBD_SLAM_format_txt);
        menuExport_poses->addAction(actionRGBD_SLAM_motion_capture_format_txt);
        menuExport_poses->addAction(actionKITTI_format_txt);
        menuExport_poses->addAction(actionTORO_graph);
        menuExport_poses->addAction(actionG2o_g2o);
        menuExport_poses->addAction(actionPoses_KML);
        menuExport_GPS->addAction(actionGPS_TXT);
        menuExport_GPS->addAction(actionGPS_KML);
        menuEdit->addAction(actionGenerate_graph_dot);
        menuEdit->addAction(actionGenerate_local_graph_dot);
        menuEdit->addSeparator();
        menuEdit->addAction(actionDetect_more_loop_closures);
        menuEdit->addAction(actionRefine_all_neighbor_links);
        menuEdit->addAction(actionRefine_all_loop_closure_links);
        menuEdit->addAction(actionUpdate_all_neighbor_covariances);
        menuEdit->addAction(actionUpdate_all_loop_closure_covariances);
        menuEdit->addSeparator();
        menuEdit->addAction(actionRegenerate_local_grid_maps);
        menuEdit->addAction(actionRegenerate_local_grid_maps_selected);
        menuEdit->addSeparator();
        menuEdit->addAction(actionEdit_depth_image);
        menuEdit->addSeparator();
        menuEdit->addAction(actionReset_all_changes);
        menuEdit->addSeparator();
        menuEdit->addAction(actionView_3D_map);
        menuView->addAction(actionVertical_Layout);

        retranslateUi(DatabaseViewer);

        comboBox_logger_level->setCurrentIndex(1);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DatabaseViewer);
    } // setupUi

    void retranslateUi(QMainWindow *DatabaseViewer)
    {
        DatabaseViewer->setWindowTitle(QApplication::translate("DatabaseViewer", "Database viewer", 0));
        actionOpen_database->setText(QApplication::translate("DatabaseViewer", "Open database", 0));
        actionQuit->setText(QApplication::translate("DatabaseViewer", "Quit", 0));
        actionGenerate_graph_dot->setText(QApplication::translate("DatabaseViewer", "Generate graph (*.dot) ...", 0));
        actionGenerate_local_graph_dot->setText(QApplication::translate("DatabaseViewer", "Generate local graph (.dot) ...", 0));
        actionGenerate_3D_map_pcd->setText(QApplication::translate("DatabaseViewer", "Export 3D map (*.ply *.pcd) ...", 0));
        actionExport->setText(QApplication::translate("DatabaseViewer", "Export database...", 0));
        actionExtract_images->setText(QApplication::translate("DatabaseViewer", "Extract images...", 0));
        actionView_3D_map->setText(QApplication::translate("DatabaseViewer", "View 3D map...", 0));
        actionRefine_all_neighbor_links->setText(QApplication::translate("DatabaseViewer", "Refine all neighbor links...", 0));
#ifndef QT_NO_TOOLTIP
        actionRefine_all_neighbor_links->setToolTip(QApplication::translate("DatabaseViewer", "Refine all neighbor links with the registration strategy set in \"Core Parameters\"->\"Reg\"", 0));
#endif // QT_NO_TOOLTIP
        actionRefine_all_loop_closure_links->setText(QApplication::translate("DatabaseViewer", "Refine all loop closure links...", 0));
#ifndef QT_NO_TOOLTIP
        actionRefine_all_loop_closure_links->setToolTip(QApplication::translate("DatabaseViewer", "Refine all loop closure links with the registration strategy set in \"Core Parameters\"->\"Reg\"", 0));
#endif // QT_NO_TOOLTIP
        actionDetect_more_loop_closures->setText(QApplication::translate("DatabaseViewer", "Detect more loop closures...", 0));
        actionSave_config->setText(QApplication::translate("DatabaseViewer", "Save config", 0));
        actionReset_all_changes->setText(QApplication::translate("DatabaseViewer", "Reset link and grid map changes", 0));
        actionRegenerate_local_grid_maps->setText(QApplication::translate("DatabaseViewer", "Regenerate local grid maps...", 0));
        actionRegenerate_local_grid_maps_selected->setText(QApplication::translate("DatabaseViewer", "Regenerate local grid maps (selected)...", 0));
        actionEdit_depth_image->setText(QApplication::translate("DatabaseViewer", "Edit depth image...", 0));
        actionVertical_Layout->setText(QApplication::translate("DatabaseViewer", "Vertical Layout", 0));
        actionRestore_default_GUI_settings->setText(QApplication::translate("DatabaseViewer", "Restore default GUI settings", 0));
        actionRaw_format_txt->setText(QApplication::translate("DatabaseViewer", "Raw format (*.txt)", 0));
#ifndef QT_NO_TOOLTIP
        actionRaw_format_txt->setToolTip(QApplication::translate("DatabaseViewer", "Raw format (12 values transform)", 0));
#endif // QT_NO_TOOLTIP
        actionRGBD_SLAM_format_txt->setText(QApplication::translate("DatabaseViewer", "RGBD-SLAM format (*.txt)", 0));
#ifndef QT_NO_TOOLTIP
        actionRGBD_SLAM_format_txt->setToolTip(QApplication::translate("DatabaseViewer", "RGBD-SLAM (stamp tx ty tz qx qy qz qw)", 0));
#endif // QT_NO_TOOLTIP
        actionKITTI_format_txt->setText(QApplication::translate("DatabaseViewer", "KITTI format (*.txt)", 0));
#ifndef QT_NO_TOOLTIP
        actionKITTI_format_txt->setToolTip(QApplication::translate("DatabaseViewer", "KITTI (stamp + 12 values transform)", 0));
#endif // QT_NO_TOOLTIP
        actionTORO_graph->setText(QApplication::translate("DatabaseViewer", "TORO (*.graph)", 0));
        actionG2o_g2o->setText(QApplication::translate("DatabaseViewer", "g2o (*.g2o)", 0));
        actionGPS_KML->setText(QApplication::translate("DatabaseViewer", "Google Earth (*.kml)", 0));
        actionGPS_TXT->setText(QApplication::translate("DatabaseViewer", "Raw format (*.txt)", 0));
        actionPoses_KML->setText(QApplication::translate("DatabaseViewer", "Google Earth (*.kml)", 0));
        actionDatabase_recovery->setText(QApplication::translate("DatabaseViewer", "Database recovery", 0));
        actionClose_database->setText(QApplication::translate("DatabaseViewer", "Close database", 0));
        actionExport_saved_2D_map->setText(QApplication::translate("DatabaseViewer", "Export optimized 2D map...", 0));
        actionImport_2D_map->setText(QApplication::translate("DatabaseViewer", "Import optimized 2D map...", 0));
        actionView_optimized_mesh->setText(QApplication::translate("DatabaseViewer", "View optimized mesh", 0));
        actionExport_optimized_mesh->setText(QApplication::translate("DatabaseViewer", "Export optimized mesh...", 0));
        actionUpdate_optimized_mesh->setText(QApplication::translate("DatabaseViewer", "Update optimized mesh...", 0));
        actionUpdate_all_neighbor_covariances->setText(QApplication::translate("DatabaseViewer", "Update all neighbor covariances...", 0));
        actionUpdate_all_loop_closure_covariances->setText(QApplication::translate("DatabaseViewer", "Update all loop closure covariances...", 0));
        actionRGBD_SLAM_motion_capture_format_txt->setText(QApplication::translate("DatabaseViewer", "RGBD-SLAM motion capture format (*.txt)", 0));
#ifndef QT_NO_TOOLTIP
        actionRGBD_SLAM_motion_capture_format_txt->setToolTip(QApplication::translate("DatabaseViewer", "RGBD-SLAM (stamp tx ty tz qx qy qz qw)", 0));
#endif // QT_NO_TOOLTIP
        actionEdit_optimized_2D_map->setText(QApplication::translate("DatabaseViewer", "Edit optimized 2D map...", 0));
        actionRegenerate_optimized_2D_map->setText(QApplication::translate("DatabaseViewer", "Regenerate optimized 2D map...", 0));
        label_poseA->setText(QString());
        label_childrenA_2->setText(QApplication::translate("DatabaseViewer", "Children", 0));
        label_parentsA->setText(QString());
        label_parentsA_2->setText(QApplication::translate("DatabaseViewer", "Parents", 0));
        label_childrenA_12->setText(QApplication::translate("DatabaseViewer", "Pose", 0));
        label_mapA->setText(QString());
        label_childrenA_10->setText(QApplication::translate("DatabaseViewer", "Map ID", 0));
        label_childrenA_14->setText(QApplication::translate("DatabaseViewer", "Calib", 0));
        label_calibA->setText(QString());
        label_childrenA->setText(QString());
        label_childrenA_4->setText(QApplication::translate("DatabaseViewer", "Label", 0));
        label_labelA->setText(QString());
        label_childrenA_6->setText(QApplication::translate("DatabaseViewer", "Stamp", 0));
        label_stampA->setText(QString());
        label_childrenA_8->setText(QApplication::translate("DatabaseViewer", "Weight", 0));
        label_weightA->setText(QString());
        label_childrenA_16->setText(QApplication::translate("DatabaseViewer", "GPS", 0));
        label_gpsA->setText(QString());
        label_childrenA_18->setText(QApplication::translate("DatabaseViewer", "Velocity", 0));
        label_velA->setText(QString());
        label_childrenA_20->setText(QApplication::translate("DatabaseViewer", "Sensors", 0));
        label_sensorsA->setText(QString());
        label_childrenA_22->setText(QApplication::translate("DatabaseViewer", "Scan", 0));
        label_scanA->setText(QString());
        label_childrenA_9->setText(QApplication::translate("DatabaseViewer", "Weight", 0));
        label_mapB->setText(QString());
        label_poseB->setText(QString());
        label_childrenA_15->setText(QApplication::translate("DatabaseViewer", "Calib", 0));
        label_calibB->setText(QString());
        label_childrenA_17->setText(QApplication::translate("DatabaseViewer", "GPS", 0));
        label_gpsB->setText(QString());
        label_childrenB->setText(QString());
        label_childrenA_5->setText(QApplication::translate("DatabaseViewer", "Label", 0));
        label_labelB->setText(QString());
        label_weightB->setText(QString());
        label_childrenA_11->setText(QApplication::translate("DatabaseViewer", "Map ID", 0));
        label_childrenA_13->setText(QApplication::translate("DatabaseViewer", "Pose", 0));
        label_parentsB->setText(QString());
        label_parentsA_4->setText(QApplication::translate("DatabaseViewer", "Parents", 0));
        label_childrenA_3->setText(QApplication::translate("DatabaseViewer", "Children", 0));
        label_childrenA_7->setText(QApplication::translate("DatabaseViewer", "Stamp", 0));
        label_stampB->setText(QString());
        label_childrenA_19->setText(QApplication::translate("DatabaseViewer", "Velocity", 0));
        label_velB->setText(QString());
        label_childrenA_21->setText(QApplication::translate("DatabaseViewer", "Sensors", 0));
        label_sensorsB->setText(QString());
        label_childrenA_23->setText(QApplication::translate("DatabaseViewer", "Scan", 0));
        label_scanB->setText(QString());
        label_2->setText(QApplication::translate("DatabaseViewer", "Index :", 0));
        label_3->setText(QApplication::translate("DatabaseViewer", "Id :", 0));
        label_indexA->setText(QApplication::translate("DatabaseViewer", "indexA", 0));
        label_idA->setText(QApplication::translate("DatabaseViewer", "idA", 0));
        label_5->setText(QApplication::translate("DatabaseViewer", "Index :", 0));
        label_4->setText(QApplication::translate("DatabaseViewer", "Id :", 0));
        label_indexB->setText(QApplication::translate("DatabaseViewer", "indexB", 0));
        label_idB->setText(QApplication::translate("DatabaseViewer", "idB", 0));
        menuFile->setTitle(QApplication::translate("DatabaseViewer", "File", 0));
        menuExport_poses->setTitle(QApplication::translate("DatabaseViewer", "Export poses...", 0));
        menuExport_GPS->setTitle(QApplication::translate("DatabaseViewer", "Export GPS...", 0));
        menuEdit->setTitle(QApplication::translate("DatabaseViewer", "Edit", 0));
        menuView->setTitle(QApplication::translate("DatabaseViewer", "View", 0));
        dockWidget_constraints->setWindowTitle(QApplication::translate("DatabaseViewer", "Constraints view", 0));
        checkBox_show3DWords->setText(QApplication::translate("DatabaseViewer", "Words", 0));
        checkBox_show3Dclouds->setText(QApplication::translate("DatabaseViewer", "Clouds", 0));
        checkBox_show2DScans->setText(QApplication::translate("DatabaseViewer", "Scans", 0));
        checkBox_odomFrame->setText(QApplication::translate("DatabaseViewer", "Odom Frame", 0));
        label_variance->setText(QString());
        label->setText(QApplication::translate("DatabaseViewer", "Neighbor links", 0));
        label_6->setText(QApplication::translate("DatabaseViewer", "Loop closure links", 0));
        label_33->setText(QApplication::translate("DatabaseViewer", "Type", 0));
        label_16->setText(QApplication::translate("DatabaseViewer", "Transform", 0));
        label_constraint->setText(QString());
        checkBox_showOptimized->setText(QApplication::translate("DatabaseViewer", "Optimized", 0));
        label_constraint_opt->setText(QString());
        label_18->setText(QApplication::translate("DatabaseViewer", "\317\203 (lin, ang), cov", 0));
        label_type->setText(QString());
        label_type_name->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_refine->setToolTip(QApplication::translate("DatabaseViewer", "Refine with the registration strategy set in \"Core Parameters\"->\"Reg\"", 0));
#endif // QT_NO_TOOLTIP
        pushButton_refine->setText(QApplication::translate("DatabaseViewer", "Refine", 0));
        pushButton_reset->setText(QApplication::translate("DatabaseViewer", "Reset", 0));
        pushButton_add->setText(QApplication::translate("DatabaseViewer", "Add", 0));
        pushButton_reject->setText(QApplication::translate("DatabaseViewer", "Reject", 0));
        dockWidget_graphView->setWindowTitle(QApplication::translate("DatabaseViewer", "Graph view", 0));
        label_iterations->setText(QApplication::translate("DatabaseViewer", "#", 0));
#ifndef QT_NO_TOOLTIP
        checkBox_iterativeOptimization->setToolTip(QApplication::translate("DatabaseViewer", "Iterative optimization. Intermediate optimization graphes will be computed. Depending on the graph optimizer used, final optimization may not give the same results.", 0));
#endif // QT_NO_TOOLTIP
        checkBox_iterativeOptimization->setText(QString());
        label_loopClosures->setText(QString());
        label_timeGrid->setText(QString());
        label_timeOptimization->setText(QString());
        label_52->setText(QApplication::translate("DatabaseViewer", "Poses", 0));
        label_39->setText(QApplication::translate("DatabaseViewer", "Time optimization (s)", 0));
        label_41->setText(QApplication::translate("DatabaseViewer", "Links (N, NM, G, LS, LT, U, P, LM, GR)", 0));
        label_10->setText(QApplication::translate("DatabaseViewer", "Path length (m)", 0));
        label_45->setText(QApplication::translate("DatabaseViewer", "Time grid (s)", 0));
        label_pathLength->setText(QString());
        label_optimizeFrom->setText(QApplication::translate("DatabaseViewer", "Root", 0));
        checkBox_spanAllMaps->setText(QApplication::translate("DatabaseViewer", "Span to all maps", 0));
        checkBox_wmState->setText(QApplication::translate("DatabaseViewer", "WM", 0));
        label_poses->setText(QString());
        label_alignPosesWithGroundTruth->setText(QApplication::translate("DatabaseViewer", "Align poses with ground truth", 0));
        checkBox_ignoreIntermediateNodes->setText(QString());
        checkBox_alignPosesWithGroundTruth->setText(QString());
        label_rmse->setText(QString());
        label_ignoreINtermediateNdoes->setText(QApplication::translate("DatabaseViewer", "Ignore intermediate nodes", 0));
        label_rmse_title->setText(QApplication::translate("DatabaseViewer", "RMSE (m)", 0));
        label_alignScansCloudsWithGroundTruth->setText(QApplication::translate("DatabaseViewer", "Align scans/clouds with ground truth", 0));
        checkBox_alignScansCloudsWithGroundTruth->setText(QString());
        dockWidget_guiparameters->setWindowTitle(QApplication::translate("DatabaseViewer", "GUI Parameters", 0));
        comboBox_logger_level->clear();
        comboBox_logger_level->insertItems(0, QStringList()
         << QApplication::translate("DatabaseViewer", "Debug", 0)
         << QApplication::translate("DatabaseViewer", "Info", 0)
         << QApplication::translate("DatabaseViewer", "Warning", 0)
         << QApplication::translate("DatabaseViewer", "Error", 0)
        );
        label_logger_level->setText(QApplication::translate("DatabaseViewer", "Logger level", 0));
        checkBox_ignoreGlobalLoop->setText(QString());
        label_49->setText(QApplication::translate("DatabaseViewer", "Ignore local loop closures (time)", 0));
        checkBox_ignoreLocalLoopSpace->setText(QString());
        label_48->setText(QApplication::translate("DatabaseViewer", "Ignore global loop closures", 0));
        label_35->setText(QApplication::translate("DatabaseViewer", "Ignore pose correction", 0));
        checkBox_ignorePoseCorrection->setText(QString());
        checkBox_ignoreLocalLoopTime->setText(QString());
        checkBox_ignoreUserLoop->setText(QString());
        label_50->setText(QApplication::translate("DatabaseViewer", "Ignore user loop closures", 0));
        label_47->setText(QApplication::translate("DatabaseViewer", "Ignore local loop closures (space)", 0));
        label_scale_title->setText(QApplication::translate("DatabaseViewer", "Scale", 0));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("DatabaseViewer", "Graph optimization", 0));
        label_51->setText(QApplication::translate("DatabaseViewer", "Gain compensation radius (Constraints view)", 0));
        doubleSpinBox_gainCompensationRadius->setSuffix(QApplication::translate("DatabaseViewer", " m", 0));
        label_53->setText(QApplication::translate("DatabaseViewer", "OctoMap", 0));
        label_54->setText(QApplication::translate("DatabaseViewer", "Voxel size (for clouds and scans)", 0));
        checkBox_octomap->setText(QString());
        checkBox_grid_regenerateFromSavedGrid->setText(QString());
        doubleSpinBox_voxelSize->setSuffix(QApplication::translate("DatabaseViewer", " m", 0));
        spinBox_grid_depth->setPrefix(QString());
        checkBox_grid_empty->setText(QString());
        label_octomap_cubes->setText(QApplication::translate("DatabaseViewer", "OctoMap: Rendering type", 0));
        comboBox_octomap_rendering_type->clear();
        comboBox_octomap_rendering_type->insertItems(0, QStringList()
         << QApplication::translate("DatabaseViewer", "Point Cloud", 0)
         << QApplication::translate("DatabaseViewer", "Cube", 0)
         << QApplication::translate("DatabaseViewer", "Volume", 0)
        );
        label_octomap_depth->setText(QApplication::translate("DatabaseViewer", "OctoMap: Tree depth", 0));
        label_55->setText(QApplication::translate("DatabaseViewer", "Local grid: regenerate from saved grid instead of sensors", 0));
        label_octomap_empty->setText(QApplication::translate("DatabaseViewer", "Show empty space", 0));
        label_octomap_empty_3->setText(QApplication::translate("DatabaseViewer", "Ground cell color", 0));
        label_octomap_empty_2->setText(QApplication::translate("DatabaseViewer", "Obstacle cell color", 0));
        label_octomap_empty_4->setText(QApplication::translate("DatabaseViewer", "Empty cell color", 0));
        toolButton_groundColor->setText(QApplication::translate("DatabaseViewer", "...", 0));
        toolButton_obstacleColor->setText(QApplication::translate("DatabaseViewer", "...", 0));
        toolButton_emptyColor->setText(QApplication::translate("DatabaseViewer", "...", 0));
        label_56->setText(QApplication::translate("DatabaseViewer", "Decimation (for images)", 0));
        spinBox_decimation->setPrefix(QString());
        groupBox_posefiltering->setTitle(QApplication::translate("DatabaseViewer", "Pose filtering", 0));
        doubleSpinBox_posefilteringAngle->setSuffix(QApplication::translate("DatabaseViewer", " degrees", 0));
        doubleSpinBox_posefilteringRadius->setSuffix(QApplication::translate("DatabaseViewer", " m", 0));
        label_42->setText(QApplication::translate("DatabaseViewer", "Radius", 0));
        label_43->setText(QApplication::translate("DatabaseViewer", "Angle", 0));
        groupBox->setTitle(QApplication::translate("DatabaseViewer", "Organized Fast Mesh", 0));
        label_14->setText(QApplication::translate("DatabaseViewer", "Triangle size", 0));
        label_12->setText(QApplication::translate("DatabaseViewer", "Angle tolerance", 0));
        spinBox_mesh_angleTolerance->setSuffix(QApplication::translate("DatabaseViewer", " deg", 0));
        spinBox_mesh_triangleSize->setSuffix(QApplication::translate("DatabaseViewer", " pix", 0));
        label_13->setText(QApplication::translate("DatabaseViewer", "Quad", 0));
        label_17->setText(QApplication::translate("DatabaseViewer", "Fill depth holes: error", 0));
        spinBox_mesh_depthError->setSuffix(QApplication::translate("DatabaseViewer", " %", 0));
        checkBox_mesh_quad->setText(QString());
        label_15->setText(QApplication::translate("DatabaseViewer", "Fill depth holes: size", 0));
        spinBox_mesh_fillDepthHoles->setSuffix(QApplication::translate("DatabaseViewer", " pix", 0));
        label_20->setText(QApplication::translate("DatabaseViewer", "Min cluster size", 0));
        spinBox_mesh_minClusterSize->setSuffix(QString());
        toolBox->setItemText(toolBox->indexOf(page_4), QApplication::translate("DatabaseViewer", "Grid/cloud generation", 0));
        label_32->setText(QApplication::translate("DatabaseViewer", "Intra-session", 0));
        doubleSpinBox_detectMore_radius->setSuffix(QApplication::translate("DatabaseViewer", " m", 0));
        label_29->setText(QApplication::translate("DatabaseViewer", "Radius", 0));
        doubleSpinBox_detectMore_angle->setSuffix(QApplication::translate("DatabaseViewer", " degrees", 0));
        label_30->setText(QApplication::translate("DatabaseViewer", "Angle", 0));
        label_31->setText(QApplication::translate("DatabaseViewer", "Iterations", 0));
        label_34->setText(QApplication::translate("DatabaseViewer", "Inter-session", 0));
        checkBox_detectMore_intraSession->setText(QString());
        checkBox_detectMore_interSession->setText(QString());
        toolBox->setItemText(toolBox->indexOf(page_5), QApplication::translate("DatabaseViewer", "Detect more loop closures", 0));
        label_9->setText(QApplication::translate("DatabaseViewer", "Decimation. Negative decimation is done from RGB size instead of depth size (if depth is smaller than RGB, it may be interpolated depending of the decimation value).", 0));
        label_11->setText(QApplication::translate("DatabaseViewer", "Max depth", 0));
        checkBox_icp_from_depth->setText(QString());
        label_7->setText(QApplication::translate("DatabaseViewer", "Generate laser scans from RGB-D images using the following parameters.", 0));
        label_19->setText(QApplication::translate("DatabaseViewer", "Min depth", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("DatabaseViewer", "Refine", 0));
        dockWidget_stereoView->setWindowTitle(QApplication::translate("DatabaseViewer", "Stereo view", 0));
        label_stereo_inliers_name->setText(QApplication::translate("DatabaseViewer", "Inliers:", 0));
        label_stereo_inliers->setText(QApplication::translate("DatabaseViewer", "0", 0));
        label_stereo_slopeOutliers_name->setText(QApplication::translate("DatabaseViewer", "Slope outliers:", 0));
        label_stereo_slopeOutliers->setText(QApplication::translate("DatabaseViewer", "0", 0));
        label_stereo_disparityOutliers_name->setText(QApplication::translate("DatabaseViewer", "Negative disparity outliers:", 0));
        label_stereo_disparityOutliers->setText(QApplication::translate("DatabaseViewer", "0", 0));
        label_stereo_flowOutliers_name->setText(QApplication::translate("DatabaseViewer", "Flow outliers:", 0));
        label_stereo_flowOutliers->setText(QApplication::translate("DatabaseViewer", "0", 0));
        dockWidget_view3d->setWindowTitle(QApplication::translate("DatabaseViewer", "3D view", 0));
        checkBox_showWords->setText(QApplication::translate("DatabaseViewer", "Words", 0));
        checkBox_showCloud->setText(QApplication::translate("DatabaseViewer", "Cloud", 0));
        checkBox_showMesh->setText(QApplication::translate("DatabaseViewer", "Mesh", 0));
        checkBox_showScan->setText(QApplication::translate("DatabaseViewer", "Scan", 0));
        checkBox_showMap->setText(QApplication::translate("DatabaseViewer", "Map", 0));
        checkBox_showGrid->setText(QApplication::translate("DatabaseViewer", "Grid", 0));
        checkBox_odomFrame_3dview->setText(QApplication::translate("DatabaseViewer", "Odom Frame", 0));
        dockWidget_info->setWindowTitle(QApplication::translate("DatabaseViewer", "Info", 0));
        dockWidget_coreparameters->setWindowTitle(QApplication::translate("DatabaseViewer", "Core Parameters", 0));
        dockWidget_statistics->setWindowTitle(QApplication::translate("DatabaseViewer", "Statistics", 0));
        checkBox_timeStats->setText(QString());
        label_logger_level_3->setText(QApplication::translate("DatabaseViewer", "Time (s) used in figures for x-axis instead of node IDs.", 0));
        dockWidget_occupancyGridView->setWindowTitle(QApplication::translate("DatabaseViewer", "Occupancy Grid", 0));
        checkBox_grid_2d->setText(QApplication::translate("DatabaseViewer", "2d Map", 0));
    } // retranslateUi

};

namespace Ui {
    class DatabaseViewer: public Ui_DatabaseViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEVIEWER_H
