import { Button, Card, CardActions, CardContent, IconButton, TextField } from "@mui/material";
import { Container } from "@mui/system";
import { useEffect, useState } from "react";
import { Link, useNavigate, useParams } from "react-router-dom";

import { Owners } from "../../models/Owners";
import EditIcon from "@mui/icons-material/Edit";
import DeleteForeverIcon from "@mui/icons-material/DeleteForever";
import ArrowBackIcon from "@mui/icons-material/ArrowBack";
import axios from "axios";
import { DEV_BACKEND_API_URL } from "../../constants";
import { toast, ToastContainer } from "react-toastify";
import "react-toastify/dist/ReactToastify.css";

export const OwnerAdd = () => {
	const navigate = useNavigate();

	const [car, setCar] = useState({
		name: "",
        addres:"",
		cnp: "",
	});

	const addCar = async (event: { preventDefault: () => void }) => {
		event.preventDefault();
		try {
			await axios.post(`${DEV_BACKEND_API_URL}/owners/`, car);
			navigate("/owners");
		} catch (error) {
			console.log(error);
		}
	};

	return (
		<Container>
			<Card>
				<CardContent>
					<IconButton component={Link} sx={{ mr: 3 }} to={`/owners`}>
						<ArrowBackIcon />
					</IconButton>{" "}
					<form onSubmit={addCar}>
						<TextField
							id="name"
							label="Name"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>)=> setCar({ ...car, name: event.target.value })}
						/>
                        <TextField
							id="addres"
							label="Address"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>) => setCar({ ...car, addres: event.target.value })}
						/>
						<TextField
							id="cnp"
							label="CNP"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>) => setCar({ ...car, cnp: event.target.value })}
						/>
						<Button type="submit">Add Owner</Button>
					</form>
				</CardContent>
				<CardActions></CardActions>
			</Card>
		</Container>
	);
};