/*==============================================================================

  Program: 3D Slicer

  Copyright (c) 2010 Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Julien Finet, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

// Qt includes
#include <QApplication>

// qMRML includes
#include <qMRMLSceneFactoryWidget.h>

// MRML includes
#include <vtkMRMLScene.h>

// STD includes

int qMRMLSceneFactoryWidgetTest1( int argc, char * argv [] )
{
  QApplication app(argc, argv);

  qMRMLSceneFactoryWidget   sceneFactory;
  sceneFactory.generateScene();
  if (sceneFactory.mrmlScene() == 0)
    {
    std::cerr << "qMRMLSceneFactoryWidget::generateScene() failed" << std::endl;
    return EXIT_FAILURE;
    }
  if (sceneFactory.mrmlScene()->GetNumberOfNodes() != 0)
    {
    std::cerr << "qMRMLSceneFactoryWidget::generateScene() failed" << std::endl;
    return EXIT_FAILURE;
    }
  sceneFactory.generateScene();
  if (sceneFactory.mrmlScene() == 0)
    {
    std::cerr << "qMRMLSceneFactoryWidget::generateScene() failed" << std::endl;
    return EXIT_FAILURE;
    }
  if (sceneFactory.mrmlScene()->GetNumberOfNodes() != 0)
    {
    std::cerr << "qMRMLSceneFactoryWidget::generateScene() failed" << std::endl;
    return EXIT_FAILURE;
    }
  // delete a node that doesn't exist: should not crash
  sceneFactory.deleteNode();
  sceneFactory.generateNode();
  if (sceneFactory.mrmlScene()->GetNumberOfNodes() != 1)
    {
    std::cerr << "qMRMLSceneFactoryWidget::generateScene() failed" << std::endl;
    return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}
