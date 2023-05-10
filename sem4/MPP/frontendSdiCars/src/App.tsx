
import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
//import React from 'react'
import { CarsShowAll } from './components/Cars/CarsShowAll'
import { CarAdd } from './components/Cars/CarsAdd'

import * as React from "react";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import { AppMenu } from './components/AppMenu'
import { CarDelete } from './components/Cars/CarDelete'
import { CarUpdate } from './components/Cars/CarUpdate'
import { AppHome } from './components/AppHome'
import { CarOwner } from './components/Statistics/CarOwnerReport'
import { RimsShowAll } from './components/Rims/RimsShowAll'
import { RimsAdd } from './components/Rims/RimsAdd'
import { RimsUpdate } from './components/Rims/RimsUpdate'
import { RimsDelete } from './components/Rims/RimsDelete'
import { OwnersShowAll } from './components/Owners/OwnersShowAll'
import { OwnerAdd } from './components/Owners/OwnersAdd'
import { OwnerUpdate } from './components/Owners/OwnersUpdate'
import { OwnerDelete } from './components/Owners/OwnersDelete'
import { OwnersCarsShowAll } from './components/OwnersCars/OwersCarsShowAll'
import { OwnersCarsAdd } from './components/OwnersCars/OwnersCarsAdd'
import { OwnersCarsUpdate } from './components/OwnersCars/OwnersCarsUpdate'
import { OwnersCarsDelete } from './components/OwnersCars/OwnersCarsDelete'
import { CarRims } from './components/Statistics/CarsRimsReport'

function App() {
  const [count, setCount] = useState(0)

  return (
    <React.Fragment>
      <Router>
        <AppMenu />

        <Routes>
          <Route path="/" element={<AppHome />} />
          <Route path="/cars" element={<CarsShowAll />} />
          <Route path="/cars/add" element={<CarAdd/>}/>
          <Route path="/cars/:carId/delete" element={<CarDelete/>}/>
          <Route path="/cars/:carId/edit" element={<CarUpdate />} />
          <Route path="/car_owner_report" element={<CarOwner/>}></Route>
          <Route path="/rims" element={<RimsShowAll />} />
          <Route path="/rims/add" element={<RimsAdd/>}/>
          <Route path="/rims/:carId/edit" element={<RimsUpdate />} />
          <Route path="/rims/:carId/delete" element={<RimsDelete/>}/>
          <Route path="/owners" element={<OwnersShowAll />} />
          <Route path="/owners/add" element={<OwnerAdd/>}/>
          <Route path="/owners/:carId/edit" element={<OwnerUpdate />} />
          <Route path="/owners/:carId/delete" element={<OwnerDelete/>}/>
          <Route path="/ownerscars" element={<OwnersCarsShowAll />} />
          <Route path="/ownerscars/add" element={<OwnersCarsAdd/>}/>
          <Route path="/ownerscars/:carId/edit" element={<OwnersCarsUpdate />} />
          <Route path="/ownerscars/:carId/delete" element={<OwnersCarsDelete/>}/>
          <Route path="/car_rims_report" element={<CarRims/>}></Route>
        </Routes>
      </Router>
    </React.Fragment>
  )
}

export default App
