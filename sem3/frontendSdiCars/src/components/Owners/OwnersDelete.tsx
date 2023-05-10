import { Container, Card, CardContent, IconButton, CardActions, Button } from "@mui/material";
import { Link, useNavigate, useParams } from "react-router-dom";
import ArrowBackIcon from "@mui/icons-material/ArrowBack";
import axios from "axios";
import { DEV_BACKEND_API_URL } from "../../constants"

export const OwnerDelete = () => {
	const { carId } = useParams();
	const navigate = useNavigate();

	const handleDelete = async (event: { preventDefault: () => void }) => {
		event.preventDefault();
		await axios.delete(`${DEV_BACKEND_API_URL}/owners/?id=${carId}`);
		
		navigate("/owners");
	};

	const handleCancel = (event: { preventDefault: () => void }) => {
		event.preventDefault();
		
		navigate("/owners");
	};

	return (
		<Container>
			<Card>
				<CardContent>
					<IconButton component={Link} sx={{ mr: 3 }} to={`/owners`}>
						<ArrowBackIcon />
					</IconButton>{" "}
					Are you sure you want to delete this Owner? This cannot be undone!
				</CardContent>
				<CardActions>
					<Button onClick={handleDelete}>Delete it</Button>
					<Button onClick={handleCancel}>Cancel</Button>
				</CardActions>
			</Card>
		</Container>
	);
};