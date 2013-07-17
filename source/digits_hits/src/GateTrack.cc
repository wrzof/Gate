#include "G4ThreeVector.hh"
#include "globals.hh"
#include "G4Track.hh"
#include "GateTrack.hh"
#include <math.h>
#include <iostream>
#include "G4VProcess.hh"
#include "G4ProcessTable.hh"
#include <vector>
#include "G4ProcessManager.hh"

   GateTrack::GateTrack()
   {m_ParentParticleName = G4String("None");
    ParticleName = G4String("UnKnown");
    VertexVolumeName = G4String("UnKnown");
    m_sourceID = 0;
    fwasKilled = 0;
   }

   GateTrack::~GateTrack()
   {}


GateTrack::GateTrack( GateTrack& aTrack)
{
   m_time =  aTrack.GetTime();
   fPosition = aTrack.GetPosition();
   fGlobalTime = aTrack.GetGlobalTime();
   fLocalTime = aTrack.GetLocalTime();
   fProperTime = aTrack.GetProperTime();
   fParentID = aTrack.GetParentID();
   fTrackID = aTrack.GetTrackID();
   fKineticEnergy = aTrack.GetKineticEnergy();
   fMomentum = aTrack.GetMomentum();
   fMDirection = aTrack.GetMomentumDirection();
   fVelocity = aTrack.GetVelocity();
   fTotalEnergy = aTrack.GetTotalEnergy();
   fVtxPosition = aTrack.GetVertexPosition();
   fVtxMomentumDirection = aTrack.GetVertexMomentumDirection();
    fPolarization = aTrack.GetPolarization();
   fVtxKineticEnergy = aTrack.GetVertexKineticEnergy();
   fWeight = aTrack.GetWeight();
// ParticleName =  aTrack.GetParticleName();

   m_PDGCode = aTrack.GetPDGCode();
   m_sourceID = aTrack.GetSourceID();

   VertexVolumeName  = aTrack.GetVertexVolumeName();
   feventID = aTrack.GetEventID();
   fRunID = aTrack.GetRunID();
   m_processName = aTrack.GetProcessName();
   ParticleName = aTrack.GetParticleName();
   fwasKilled = aTrack.GetWasKilled();
   m_ParentParticleName = aTrack.GetParentParticleName();
}

G4bool GateTrack::Compare( G4Track* aTrack)
{
/*
  G4bool test1 = fabs( fPosition.x() - aTrack->GetPosition().x() ) < .00000001;
  G4bool test2 = test1 && ( fabs( fPosition.y() - aTrack->GetPosition().y() ) < .00000001 );
  G4bool test3 = test2 && ( fabs( fPosition.z() - aTrack->GetPosition().z() ) < .00000001 );
  G4bool test4 = test3 && ( fabs( fMomentum.x() - aTrack->GetMomentum().x() ) < .00000001 );
  G4bool test5 = test4 && ( fabs( fMomentum.y() - aTrack->GetMomentum().y() ) < .00000001 );
  G4bool test6 = test5 && ( fabs( fMomentum.z() - aTrack->GetMomentum().z() ) < .00000001 );
*/

//G4cout <<" GateTrack::Compare  position GateTrack " <<fPosition <<"    position G4Track "<<aTrack->GetPosition()<<G4endl;


//G4cout <<" GateTrack::Compare  momentum GateTrack " <<fMomentum <<"    position G4Track "<<aTrack->GetMomentum()<<G4endl;
G4ThreeVector diffVect = fPosition - aTrack->GetPosition();


G4bool test1 = diffVect.mag() < 0.00000001;

return test1;


//diffVect = fMomentum - aTrack->GetMomentum();
//G4bool test2 = diffVect.mag() < 0.00000001;
//if ( test2 == false ) { return false;}
//return true;

/*
  G4bool test1 = fabs( fPosition.x() - aTrack->GetPosition().x() ) < .00000001;
  if ( test1 == false ) {return false;}
  G4bool test2 = fabs( fPosition.y() - aTrack->GetPosition().y() ) < .00000001;
  if ( test2 == false ) {return false;}
  G4bool test3 = fabs( fPosition.z() - aTrack->GetPosition().z() ) < .00000001;
  if ( test3 == false ) {return false;}
  G4bool test4 = fabs( fMomentum.x() - aTrack->GetMomentum().x() ) < .00000001;
  if ( test4 == false ) {return false;}
  G4bool test5 = fabs( fMomentum.y() - aTrack->GetMomentum().y() ) < .00000001;
  if ( test5 == false ) {return false;}
  G4bool test6 = fabs( fMomentum.z() - aTrack->GetMomentum().z() ) < .00000001;
  if ( test6 == false ) {return false;}
*/


//G4cout << " position Gate Track " << fPosition << G4endl;
//G4cout << " position G4   Track " << aTrack->GetPosition()<<G4endl;
//G4cout << " Gate Track momentum " << fMomentum<<"      G4 Track  "<<aTrack->GetMomentum() << G4endl;
//G4cout << " test1 = " << std::boolalpha << test1 << G4endl;


//G4cout << " test2 = " << std::boolalpha << test2 << G4endl;

/*
G4cout << " test3 = " << std::boolalpha << test3 << G4endl;
G4cout << " test4 = " << std::boolalpha << test4 << G4endl;
G4cout << " test5 = " << std::boolalpha << test5 << G4endl;
G4cout << " test6 = " << std::boolalpha << test6 << G4endl;
*/
 G4cout <<" ====================== "<<G4endl;


//return true;

}

void GateTrack::Fill_Track( G4Track * aTrack)
{
    fPosition = aTrack->GetPosition();
   fGlobalTime = aTrack->GetGlobalTime();
   fLocalTime = aTrack->GetLocalTime();
   fProperTime = aTrack->GetProperTime();
   fParentID = aTrack->GetParentID();
   fTrackID = aTrack->GetTrackID();
   fKineticEnergy = aTrack->GetKineticEnergy();
   fMomentum = aTrack->GetMomentum();
   fMDirection = aTrack->GetMomentumDirection();
   fVelocity = aTrack->GetVelocity();
   fTotalEnergy = aTrack->GetTotalEnergy();
   fVtxPosition = aTrack->GetVertexPosition();
   fVtxMomentumDirection = aTrack->GetVertexMomentumDirection();
    fPolarization = aTrack->GetPolarization();
   fVtxKineticEnergy = aTrack->GetVertexKineticEnergy();
   fWeight = aTrack->GetWeight();

if( aTrack->GetDefinition() != 0 ) {  ParticleName =  aTrack->GetDefinition()->GetParticleName();
				      m_PDGCode =  aTrack->GetDefinition()->GetPDGEncoding(); }

 VertexVolumeName  = G4String("OutOfWorld");
if( aTrack->GetLogicalVolumeAtVertex() != 0 ) { VertexVolumeName  = aTrack->GetLogicalVolumeAtVertex()->GetName();}

// get the process name

G4String processName = " Event Generator";

G4VProcess* theProcess = const_cast<G4VProcess*> ( aTrack->GetCreatorProcess() );

// get the name of the particle which created this particle !

if ( theProcess != 0 )
{m_ParentParticleName = theProcess->GetProcessManager()->GetParticleType()->GetParticleName();
 processName =  aTrack->GetCreatorProcess()->GetProcessName();
}

m_processName = processName;

}
// parent track ID
    G4int GateTrack::GetParentID()
   { return fParentID; }


 G4String GateTrack::GetVertexVolumeName()
 {return VertexVolumeName; }

void GateTrack::SetVertexVolumeName(G4String aName)
 {VertexVolumeName = aName; }


    void GateTrack::SetParticleName(  G4String aName )
    { ParticleName = aName; }

    G4String GateTrack::GetParticleName()
    {return ParticleName; }

    void GateTrack::SetParentID(const G4int aValue)
   { fParentID = aValue; }

// current track ID
    G4int GateTrack::GetTrackID()
   { return fTrackID; }

    void GateTrack::SetTrackID(const G4int aValue)
   { fTrackID = aValue; }

    G4int GateTrack::GetEventID()
   { return feventID; }

    void GateTrack::SetEventID(const G4int aValue)
   { feventID = aValue; }

    G4int GateTrack::GetRunID()
   { return fRunID; }

    void GateTrack::SetRunID(const G4int aValue)
   { fRunID = aValue; }

// position
    G4ThreeVector& GateTrack::GetPosition()
   { return fPosition; }

    void GateTrack::SetPosition(const G4ThreeVector& aValue)
   { fPosition = aValue; }

// global time
    G4double GateTrack::GetGlobalTime()
   { return fGlobalTime; }

    void GateTrack::SetGlobalTime(const G4double aValue)
   { fGlobalTime = aValue; }
     // Time since the event in which the track belongs is created.

// local time
    G4double GateTrack::GetLocalTime()
   { return fLocalTime; }

    void GateTrack::SetLocalTime(const G4double aValue)
   { fLocalTime = aValue; }
      // Time since the current track is created.

// proper time
    G4double GateTrack::GetProperTime()
   { return fProperTime; }

    void GateTrack::SetProperTime(const G4double aValue)
   { fProperTime = aValue; }
      // Proper time of the current track


// kinetic energy
    G4double GateTrack::GetKineticEnergy()
   { return fKineticEnergy; }

    void GateTrack::SetKineticEnergy(const G4double aValue)
   { fKineticEnergy = aValue; }

// total energy
    G4double GateTrack::GetTotalEnergy()
   { return fTotalEnergy; }

   void GateTrack::SetTotalEnergy(G4double Energy)
   { fTotalEnergy = Energy; }


// momentum
    G4ThreeVector GateTrack::GetMomentum()
   { return fMomentum; }

    void GateTrack::SetMomentum( G4ThreeVector aVector )
{ fMomentum = aVector; }

// momentum (direction)
   G4ThreeVector& GateTrack::GetMomentumDirection()
   { return fMDirection ; }

    void GateTrack::SetMomentumDirection(const G4ThreeVector& aValue)
   { fMDirection = aValue ; }

// polarization

   G4ThreeVector& GateTrack::GetPolarization()
   { return fPolarization; }

    void GateTrack::SetPolarization(const G4ThreeVector& aValue)
   { fPolarization = aValue; }

    void GateTrack::SetVertexPosition(G4ThreeVector& aValue)
   { fVtxPosition = aValue; }

    G4ThreeVector& GateTrack::GetVertexPosition()
   { return fVtxPosition; }

    G4ThreeVector& GateTrack::GetVertexMomentumDirection()
   { return fVtxMomentumDirection; }

   void GateTrack::SetVertexMomentumDirection(const G4ThreeVector& aValue)
   { fVtxMomentumDirection = aValue ;}

   G4double GateTrack::GetVertexKineticEnergy()
   { return fVtxKineticEnergy; }

  void GateTrack::SetVertexKineticEnergy(const G4double aValue)
   { fVtxKineticEnergy = aValue; }

// track weight
   void  GateTrack::SetWeight(G4double aValue)
   { fWeight = aValue; }

    G4double GateTrack::GetWeight()
   { return fWeight; }

   G4double GateTrack::GetVelocity()
 { return fVelocity;}

   void GateTrack::SetVelocity(G4double aVelocity)
 {fVelocity = aVelocity;}

   void GateTrack::Print()
{
     G4cout<< " *********************************************************\n";
     G4cout << "            GateTrack Data Informations                    "<<G4endl;
     G4cout << " RunID " << fRunID<< "             EventID = " << feventID << G4endl;
     G4cout << " Primary Particle " <<  ParticleName << G4endl;
     G4cout << " Source ID        " <<  m_sourceID << G4endl;
     G4cout << " Position " << fPosition << "     Track    ID " << fTrackID <<"      Parent ID " << fParentID << G4endl;
     G4cout <<"  Local Time " << fLocalTime<< "      Proper Time " << fProperTime << "          Momentum Direction "<< fMDirection <<G4endl;
     G4cout << " Momentum " << fMomentum << "           Energy " << fTotalEnergy << "              Kinetic Energy " << fKineticEnergy << "                  Velocity " << fVelocity << "\n";
     G4cout << " Vertex Position      "<< fVtxPosition<<G4endl;
     G4cout << " Vertex Momentum Direction "<<fVtxMomentumDirection <<G4endl;
     G4cout << " Polarization              "<<fPolarization<<G4endl;
     G4cout << " Vertex Kinetic Energy     " << fVtxKineticEnergy <<G4endl;
     G4cout << " Weight                    " << fWeight << G4endl;
     G4cout << " Volume Name at Vertex     " << VertexVolumeName << G4endl;
     G4cout << " Process Name                    " << m_processName << G4endl;
     G4cout<< " *********************************************************\n";


}
