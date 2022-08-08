/**********************************************************************
 *  N-Body Simulation
 **********************************************************************/

/**********************************************************************
 *  Introduction
 **********************************************************************/
    This project main idea is to show all planets in the window by using planets.txt file.
    In addition, the project asks us to use smartpointer as well. The following are what 
    I have done in the project:

    -Feature one: Drawing using window.draw(obj)
        I accomplished this figure by looping through the vector of sharepointer of Celestialboby
    objects.Since I already stored each planet information and image file in the vector of sharepointer
    , I could display each planet by puting object of Celestialboby into draw function.(example "*cb[start] ").
    The following is the code example from my project:

        //loop for display all planets
		for(unsigned int start=0; start<numOfParticle; start++)
            windowDiplay.draw((*cb[start]));

    -Feature two: Implementation loads universe from stdin
        For this feature, I use stream extraction operator ">>" to perform overloading operation
    It is pretty straightforward. Below is my code:

        //StreamInput
        istream &operator >> (istream &input, CelestialBody &c){
        input >> c.pos_X >> c.pos_Y >> c.vel_X >>c.vel_Y >>c.mass >>c.img_Name;
        c.set_Img(c.img_Name);
        return input;

    -Feature three: Supporting arbitrary number of body object per universe file
        The way I managed the arbitrary number of body object per universe file is that
    , I used vector of sharedpointer to store each property of planet.Hence, I am able to 
    draw each objects in window.draw function easily.

    -Feature four: Scaling arbitrary universe size and window size
        In general the SFML's point is in the upper-left and the universe center is in (0,0) 
    position. To adjustment of the center point, I had to divide the window size by 2.Hence,
    I would get correct SFML points which match the universe center (0,0). Therefore, I used 
    given radius value which extracted from planets.txt. to calucate the pixel value per distance
    by dividing given radius by half size of the window size. In addition, to properly scale the 
    planets based on universe size, I had to set seperate conditions for coordinate x and coordinate 
    y. In order to get precise x coordinate position, the x coordinate will be located in center     positive
    if only x coordinate is a positive value. On the other hand, x coordinate will be subtracted
    from the center if x coordinate is a negative value. In addition, if y coordinate contains 
    positive value, it would subtract from the center and vice versa.


    -Feature five: Using smartpointer
            I used vector of shared_ptr to point to Celestialboby object which allows me to use
    stream extraction operator to take in each planet details, then pass into Celestialboby and 
    define each variables and store in each vector location. 

B-How to run the program.

 Step 1: goes to MATE terminal
 Step 2: goes to folder ps3a
 Step 3: type "Make" in command line
 Step 4: type ./NBody <planets.txt
          

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the Project.
 **********************************************************************/
    The key algorithms of this assignment is following:    

    -Feature four: Scaling arbitrary universe size and window size

        In general the SFML's point is in the upper-left and the universe center is in (0,0) 
    position. To adjustment of the center point, I had to divide the window size by 2.Hence,
    I would get correct SFML points which match the universe center (0,0). Therefore, I used 
    given radius value which extracted from planets.txt. to calucate the pixel value per distance
    by dividing given radius by half size of the window size. In addition, to properly scale the 
    planets based on universe size, I had to set seperate conditions for coordinate x and coordinate 
    y. In order to get precise x coordinate position, the x coordinate will be located in center     positive
    if only x coordinate is a positive value. On the other hand, x coordinate will be subtracted
    from the center if x coordinate is a negative value. In addition, if y coordinate contains 
    positive value, it would subtract from the center and vice versa.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/

    I used sharepointer in my program to point to Celestialboby object.
The following is my implementation of code.

        // Create sharepointer of vector which point to CelestialBody
            std::vector<std::shared_ptr<CelestialBody>> cb;
            for(unsigned int start=0; start<numOfParticle; start++){
                std::shared_ptr<CelestialBody> p(new CelestialBody());
                cb.push_back(p);
            }
    
    The way I used the vector-smart pointer is that, I created vector of
sharepointer to able me to point object of Celestialboby and use stream 
extraction operator to take in each planet details, then pass into Celestialboby and 
define each variables and store in each vector location .Hence, when I call the pointer
of the object to print the images in the window. 
                           
 *****************************************
