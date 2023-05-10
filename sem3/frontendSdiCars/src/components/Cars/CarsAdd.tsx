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

export const CarAdd = () => {
	const navigate = useNavigate();

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
			await axios.post(`${DEV_BACKEND_API_URL}/cars/`, car);
			navigate("/cars");
		} catch (error) {
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
						<Button type="submit">Add Car</Button>
					</form>
				</CardContent>
				<CardActions></CardActions>
			</Card>
		</Container>
	);
};
