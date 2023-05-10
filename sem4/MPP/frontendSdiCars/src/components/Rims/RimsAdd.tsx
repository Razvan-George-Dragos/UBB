import { Autocomplete, Button, Card, CardActions, CardContent, IconButton, TextField } from "@mui/material";
import { Container } from "@mui/system";
import { useCallback, useEffect, useState } from "react";
import { Link, useNavigate, useParams } from "react-router-dom";
import { Rim } from "../../models/Rims";
import EditIcon from "@mui/icons-material/Edit";
import DeleteForeverIcon from "@mui/icons-material/DeleteForever";
import ArrowBackIcon from "@mui/icons-material/ArrowBack";
import axios from "axios";
import { DEV_BACKEND_API_URL } from "../../constants"
import { Car } from "../../models/Cars";
import { debounce } from "lodash";
import { toast, ToastContainer } from "react-toastify";
import "react-toastify/dist/ReactToastify.css";


export const RimsAdd = () => {
	const navigate = useNavigate();
    const [carss, setCarss] = useState<Car[]>([]);
	const [car, setCar] = useState({
		rimBrand: "",
        rimModel:"",
		height: 1,
        width: 1,
        carModel: 1,
	});

    const fetchSuggestions = async (query: string) => {
		try {
			let url = `${DEV_BACKEND_API_URL}/carOrdByBrand/${query}`;
			await fetch(url).then(async(response)=>{
				const jsn = await response.json();
				setCarss(jsn);
				console.log(jsn);
			}); 
			//const response = await fetch(url);
			//const { count, next, previous, results } = await response.json();
			//setCarss(results);
			//console.log(results);
		} catch (error) {
			console.error("Error fetching suggestions:", error);
		}
	};

    const debouncedFetchSuggestions = useCallback(debounce(fetchSuggestions, 500), []);

	useEffect(() => {
		return () => {
			debouncedFetchSuggestions.cancel();
		};
	}, [debouncedFetchSuggestions]);
	

    const handleInputChange = (event: any, value: any, reason: any) => {
		console.log("input", value, reason);

		if (reason === "input") {
			debouncedFetchSuggestions(value);
		}
	};

	const addCar = async (event: { preventDefault: () => void }) => {
		event.preventDefault();
		try {
			if(car.height>25 || car.height<10){
				throw new Error("You can't have a road legal car with heigher than 25 wheels or lower than 10");
			}
			await axios.post(`${DEV_BACKEND_API_URL}/rims/`, car);
			navigate("/rims");
		} catch (error) {
			toast.error((error as { message: string }).message);
			console.log(error);
		}
	};

	return (
		<Container>
			<Card>
				<CardContent>
					<IconButton component={Link} sx={{ mr: 3 }} to={`/rims`}>
						<ArrowBackIcon />
					</IconButton>{" "}
					<form onSubmit={addCar}>
						<TextField
							id="rimBrand"
							label="Rim Brand"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>)=> setCar({ ...car, rimBrand: event.target.value })}
						/>
                        <TextField
							id="rimModel"
							label="Model"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>) => setCar({ ...car, rimModel: event.target.value })}
						/>
						<TextField
							id="height"
							label="Height"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>) => setCar({ ...car, height: Number(event.target.value) })}
						/>
						 <TextField
							id="width"
							label="Width"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>) => setCar({ ...car, width: Number(event.target.value) })}
						/>
                        <Autocomplete
							id="carModel"
							options={carss}
							renderInput={(params) => <TextField {...params} label="Car" variant="outlined" />}
							getOptionLabel={(option) => `${option.brand} - ${option.mod}`}
							//filterOptions={(options, state) => options.filter((option) => option.brand.toLowerCase().includes(state.inputValue.toLowerCase()))}

							onInputChange={handleInputChange}
							onChange={(event, value) => {
								if (value) {
									console.log(value);
									setCar({ ...car, carModel: value.id });
								}
							}}
							
						/>
						<ToastContainer/>
						<Button type="submit">Add Rim</Button>
					</form>
				</CardContent>
				<CardActions></CardActions>
			</Card>
		</Container>
	);
};
