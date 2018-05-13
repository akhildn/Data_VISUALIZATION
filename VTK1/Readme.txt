/****************** Project 1 ***********************/

/* Name : Akhil Nayabu
   UID : 2000075395 */



** Objective : A height Field is a regular array of 2D points h = f(x; y) where h is an altitude above the point
(x; y). Height Field is often used to represent terrain data, and can sometimes be generated using
a gray-scale image, where the gray-scale value at each pixel is treated as the altitude at the pixel
location. For the given gray-scale image, generate a height Field dataset, and then write a VTK
program to visualize this height Field. Please use an interactor to allow the user to interact with
your visualization.

** Tools required to run : visual studio 2017, cmake, vtk 8.1.0

** How to run :
-> open cmake 
->give source path as : ../project1
->give build path as : ../project1/build
->press configure, if you get an error with missing vtk unkown path then gove vtk's bin path where ever it is located.
->press generate.
->once generated, in build solution for project is created.
->open solution and do "ALL BUILD"
->once built go to debug folder where .exe is is generated. 
->add Heightmap.png into debuf folder before you run .exe file.

** Output screenshots are added to output folder.

** Dataset Description
-> A grayscale image. 
-> 257 * 257 pixels.
-> Value at each pixel is treated as height field.

** VTK methods
-> vtkPNGReader : to read input image.
-> vtkImageData : to store imagedata of read png image.
-> GetScalarComponentAsDouble : gets x, y, z components of image.
-> vtkPolyData : since terrain is a 3d image, you need polydata to store these points.
