/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include "tao/corba.h"
#include <orbsvcs/orbsvcs/CosNamingC.h>
#include "crypt.h"
#include "../cpp/CalcImpl.h"

using namespace std;

int main(int argc, char** argv) {
    // Declare ORB and servant object
    CORBA::ORB_var orb;
    // CalcImpl* calcImpl = NULL;
    PortableServer::Servant_var<CalcImpl> mycalc;
    
    try {
        // Initialize the ORB.
        orb = CORBA::ORB_init(argc, argv);
        // Get a reference to the root POA
        CORBA::Object_var rootPOAObj =
                orb->resolve_initial_references("RootPOA");
        // Narrow it to the correct type
        PortableServer::POA_var rootPOA =
                PortableServer::POA::_narrow(rootPOAObj.in());


        // Get the POA manager object
        PortableServer::POAManager_var manager = rootPOA->the_POAManager();

        mycalc = new CalcImpl();
        mycalc->orb(orb);
        
        // Activate the object. This tells the POA that this object is
        // ready to accept requests.
        PortableServer::ObjectId_var mycalcid = rootPOA->activate_object(mycalc.in());
        
       // Obtain a reference to the object.
        ::br::org::joe::Calc_var mycalcref = mycalc->_this();

        // Activate the POA
        manager->activate();
        cout << "The server is ready.  Awaiting for incoming requests..." << endl;
        CORBA::String_var ior = orb->object_to_string(mycalc->_this());

        ofstream serverIofFile;
        serverIofFile.open("../server.ior");
        serverIofFile << ior << endl;
        serverIofFile.close();
        cout << "Reference is : " << ior << endl;

        // Start the ORB
        orb->run();

    } catch (const CORBA::Exception& e) {
        // Handles CORBA exceptions
        cerr << e << endl;
    }

    // Decrement reference count
    if (mycalc)
        mycalc->_remove_ref();

    // End CORBA
    if (!CORBA::is_nil(orb)) {
        try {
            orb->destroy();
            cout << "Ending CORBA..." << endl;
        } catch (const CORBA::Exception& e) {
            cout << "orb->destroy() failed:" << e << endl;
            return 1;
        }
    }
    return 0;
}
