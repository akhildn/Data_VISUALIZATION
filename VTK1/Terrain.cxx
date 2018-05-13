/*Name : Akhil Nayabu*/


using namespace std;
#include <vtkVersion.h>
#include <vtkNew.h>
#include <vtkPNGReader.h>
#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkDelaunay2D.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>

int main(int, char *[])
{
	// read png input file.
	vtkSmartPointer<vtkPNGReader> pngImage =
		vtkSmartPointer<vtkPNGReader>::New();
	pngImage->SetFileName("Heightmap.png");
	pngImage->Update();

	// to store image data of Heightmap.png
	vtkSmartPointer<vtkImageData> imageData;
	imageData = pngImage->GetOutput();

	// gets x,y,z dimensions of image 
	int* dimensions = imageData->GetDimensions();

	cout << "Dimensions - " << " x: " << dimensions[0] << " y: " << dimensions[1] << " z: " << dimensions[2] << endl;
	cout << "Number of points: " << imageData->GetNumberOfPoints() << endl;

	// Used to store image points 
	vtkSmartPointer<vtkPoints> points =
		vtkSmartPointer<vtkPoints>::New();

	cout << "data loading please wait for interactor" << endl;
	for (int z = 0; z < dimensions[2]; z++)
	{
		for (int y = 0; y < dimensions[1]; y++)
		{
			for (int x =0; x < dimensions[0]; x++)
			{
				int v = imageData->GetScalarComponentAsDouble(x, y, z, 0);
				points->InsertNextPoint(x, y, v);
			}
		}
	}

	// to store the image points in polydata
	vtkSmartPointer<vtkPolyData> polydata =
		vtkSmartPointer<vtkPolyData>::New();
	polydata->SetPoints(points);

	//triangulate the grid points
	vtkSmartPointer<vtkDelaunay2D> delaunay =
		vtkSmartPointer<vtkDelaunay2D>::New();

	delaunay->SetInputData(polydata);
	delaunay->Update();

	// Create a mapper
	vtkSmartPointer<vtkPolyDataMapper> mapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(delaunay->GetOutputPort());

	// Create an actor
	vtkSmartPointer<vtkActor> actor =
		vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);

	// A renderer and render window
	vtkSmartPointer<vtkRenderer> renderer =
		vtkSmartPointer<vtkRenderer>::New();

	vtkSmartPointer<vtkRenderWindow> renderWindow =
		vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);

	// An interactor
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow);

	// Add the actors to the scene
	renderer->AddActor(actor);
	renderer->SetBackground(.2, .4, .4);

	// Render an image (lights and cameras are created automatically)
	renderWindow->Render();
	// Begin mouse interaction

	renderWindowInteractor->Start();

	int i;
	cin >> i;
}
