import { Button, Card, CardActions, CardContent, IconButton, TextField } from "@mui/material";
import { Container } from "@mui/system";
import { useEffect, useState } from "react";
import { Link, useNavigate, useParams } from "react-router-dom";

import { Car } from "../../models/Cars";
import EditIcon from "@mui/icons-material/Edit";
import DeleteForeverIcon from "@mui/icons-material/DeleteForever";
import ArrowBackIcon from "@mui/icons-material/ArrowBack";
import axios from "axios";
import { DEV_BACKEND_API_URL } from "../../constants"
import { toast, ToastContainer } from "react-toastify";
import "react-toastify/dist/ReactToastify.css";
export const CarAdd = () => {
	const navigate = useNavigate();
	//const [errorMessage, setErrorMessage] = useState("");
	const [car, setCar] = useState({
		brand: "",
        mod:"",
		chasisNr: 1,
        hp: 1,
        yearOfRegistration: 1,
	});

	const addCar = async (event: { preventDefault: () => void }) => {
		event.preventDefault();
		try {
			if(car.yearOfRegistration<1875 || car.yearOfRegistration>2023 || car.hp<2 || car.hp>3000){
				throw new Error("Invalid dates for yearOfReagistration or horse power");
			}
			await axios.post(`${DEV_BACKEND_API_URL}/cars/`, car);
			navigate("/cars");
		} catch (error) {
			toast.error((error as { message: string }).message);
			//setErrorMessage((error as { message: string }).message);
			console.log(error);
		}
	};

	return (
		<Container>
			<Card>
				<CardContent>
					<IconButton component={Link} sx={{ mr: 3 }} to={`/cars`}>
						<ArrowBackIcon />
					</IconButton>{" "}
					<form onSubmit={addCar}>
						<TextField
							id="brand"
							label="Car Brand"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>)=> setCar({ ...car, brand: event.target.value })}
						/>
                        <TextField
							id="mod"
							label="Model"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>) => setCar({ ...car, mod: event.target.value })}
						/>
						<TextField
							id="chasisNr"
							label="Chasis nr"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>) => setCar({ ...car, chasisNr: Number(event.target.value) })}
						/>
						 <TextField
							id="hp"
							label="Horse Power"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>) => setCar({ ...car, hp: Number(event.target.value) })}
						/>
						 <TextField
							id="yearOfRegistration"
							label="Year of registration"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>) => setCar({ ...car, yearOfRegistration: Number(event.target.value) })}
						/>
						<ToastContainer/> 
						<Button type="submit">Add Car</Button>
					</form>
				</CardContent>
				<CardActions></CardActions>
			</Card>
		</Container>
	);
};
