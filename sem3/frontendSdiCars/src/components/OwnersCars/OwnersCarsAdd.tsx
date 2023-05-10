import { Autocomplete, Button, Card, CardActions, CardContent, IconButton, TextField } from "@mui/material";
import { Container } from "@mui/system";
import { useCallback, useEffect, useState } from "react";
import { Link, useNavigate, useParams } from "react-router-dom";
import { Owners } from "../../models/Owners";
import EditIcon from "@mui/icons-material/Edit";
import DeleteForeverIcon from "@mui/icons-material/DeleteForever";
import ArrowBackIcon from "@mui/icons-material/ArrowBack";
import axios from "axios";
import { DEV_BACKEND_API_URL } from "../../constants"
import { Car } from "../../models/Cars";
import { debounce } from "lodash";
import { OwnersCars } from "../../models/OwnersCars";



export const OwnersCarsAdd = () => {
	const navigate = useNavigate();
    const [carss, setCarss] = useState<Car[]>([]);
    const [owners, setOwners] = useState<Owners[]>([]);
	const [car, setCar] = useState({
		price: 1,
        kmWhenBought:1,
		car: 1,
        owner: 1,
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
    const fetchSuggestions2 = async (query: string) => {
		try {
			let url = `${DEV_BACKEND_API_URL}/ownersOrdByName/${query}`;
			await fetch(url).then(async(response)=>{
				const jsn = await response.json();
				setOwners(jsn);
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
    const debouncedFetchSuggestions2 = useCallback(debounce(fetchSuggestions2, 500), []);
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
    const handleInputChange2 = (event: any, value: any, reason: any) => {
		console.log("input", value, reason);

		if (reason === "input") {
			debouncedFetchSuggestions2(value);
		}
	};

	const addCar = async (event: { preventDefault: () => void }) => {
		event.preventDefault();
		try {
			await axios.post(`${DEV_BACKEND_API_URL}/ownerscars/`, car);
			navigate("/ownerscars");
		} catch (error) {
			console.log(error);
		}
	};

	return (
		<Container>
			<Card>
				<CardContent>
					<IconButton component={Link} sx={{ mr: 3 }} to={`/ownerscars`}>
						<ArrowBackIcon />
					</IconButton>{" "}
					<form onSubmit={addCar}>
						<TextField
							id="price"
							label="Price"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>)=> setCar({ ...car, price: Number(event.target.value) })}
						/>
                        <TextField
							id="kmWhenBought"
							label="Km when bought"
							variant="outlined"
							fullWidth
							sx={{ mb: 2 }}
							onChange={(event: React.ChangeEvent<HTMLInputElement>) => setCar({ ...car, kmWhenBought: Number(event.target.value) })}
						/>
						<Autocomplete
							id="car"
							options={carss}
							renderInput={(params) => <TextField {...params} label="Car" variant="outlined" />}
							getOptionLabel={(option) => `${option.brand} - ${option.mod}`}
							//filterOptions={(options, state) => options.filter((option) => option.brand.toLowerCase().includes(state.inputValue.toLowerCase()))}

							onInputChange={handleInputChange}
							onChange={(event, value) => {
								if (value) {
									console.log(value);
									setCar({ ...car, car: value.id });
								}
							}}
							
						/>
                        <Autocomplete
							id="owner"
							options={owners}
							renderInput={(params) => <TextField {...params} label="Owners" variant="outlined" />}
							getOptionLabel={(option) => `${option.name} - ${option.addres}`}
							//filterOptions={(options, state) => options.filter((option) => option.brand.toLowerCase().includes(state.inputValue.toLowerCase()))}

							onInputChange={handleInputChange2}
							onChange={(event, value) => {
								if (value) {
									console.log(value);
									setCar({ ...car, owner: value.id });
								}
							}}
							
						/>
						<Button type="submit">Add OwnersCars</Button>
					</form>
				</CardContent>
				<CardActions></CardActions>
			</Card>
		</Container>
	);
};