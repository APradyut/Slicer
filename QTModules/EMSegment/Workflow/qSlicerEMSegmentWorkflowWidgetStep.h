/*==============================================================================

  Program: 3D Slicer

  Copyright (c) 2010 Kitware Inc.

  See Doc/copyright/copyright.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by
    Danielle Pace and Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

#ifndef __qSlicerEMSegmentWorkflowWidgetStep_h
#define __qSlicerEMSegmentWorkflowWidgetStep_h

// CTK includes
#include <ctkPimpl.h>
#include <ctkWorkflowWidgetStep.h>
#include <ctkWorkflowTransitions.h>

// EMSegment includes
#include "qSlicerEMSegmentWidget.h"

class qSlicerEMSegmentWorkflowWidgetStepPrivate;
class qSlicerEMSegmentWorkflowWidget;
class vtkEMSegmentMRMLManager;
class vtkSlicerEMSegmentLogic;

class qSlicerEMSegmentWorkflowWidgetStep : public ctkWorkflowWidgetStep
{
  Q_OBJECT

public:

  typedef ctkWorkflowWidgetStep Superclass;
  explicit qSlicerEMSegmentWorkflowWidgetStep(ctkWorkflow* newWorkflow, 
                                              const QString& newId, QWidget* newParent = 0);
  explicit qSlicerEMSegmentWorkflowWidgetStep(QWidget* newParent = 0);

  vtkMRMLScene *           mrmlScene() const;
  vtkEMSegmentMRMLManager* mrmlManager() const;

  void setEMSegmentLogic(vtkSlicerEMSegmentLogic* logic);

public slots:
  void setMRMLManager(vtkEMSegmentMRMLManager * newMRMLManager);

signals:

  void mrmlSceneChanged(vtkMRMLScene* newMRMLScene);

  void mrmlManagerChanged(vtkEMSegmentMRMLManager* newMRMLManager);

protected:

  vtkSlicerEMSegmentLogic* emSegmentLogic()const;

private:
  CTK_DECLARE_PRIVATE(qSlicerEMSegmentWorkflowWidgetStep);

};

#endif
