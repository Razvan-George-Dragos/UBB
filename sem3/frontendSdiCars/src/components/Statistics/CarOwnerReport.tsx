import {
	TableContainer,
	Paper,
	Table,
	TableHead,
	TableRow,
	TableCell,
	TableBody,
	CircularProgress,
	Container,
	IconButton,
	Tooltip,
} from "@mui/material";
import ArrowUpwardIcon from "@mui/icons-material/ArrowUpward";
import ArrowDownwardIcon from "@mui/icons-material/ArrowDownward";
import { Link } from "react-router-dom";
import { Car } from "../../models/Cars";
import ReadMoreIcon from "@mui/icons-material/ReadMore";
import EditIcon from "@mui/icons-material/Edit";
import DeleteForeverIcon from "@mui/icons-material/DeleteForever";
import AddIcon from "@mui/icons-material/Add";
import { DEV_BACKEND_API_URL } from "../../constants"
import { useState, useEffect } from "react";
import axios from "axios"

interface Statistic {
	id: number;
	name: string;
	num_cars: number;
}

export const CarOwner = () => {
    const [statistics, setStatistics] = useState<Statistic[]>([]);
    const [loading, setLoading] = useState(false);
    const [sortOrder, setSortOrder] = useState<'asc' | 'desc'>('asc'); // initial sort order is ascending
  
    useEffect(() => {
      setLoading(true);
      axios
        .get(`${DEV_BACKEND_API_URL}/car_owner_report/`)
        .then((response) => {
          setStatistics(response.data);
          setLoading(false);
        })
        .catch((error) => {
          console.error(error);
          setLoading(false);
        });
    }, []);
  
    const handleSortOrderChange = () => {
      setSortOrder(sortOrder === 'asc' ? 'desc' : 'asc'); // toggle sort order between ascending and descending
    };
  
    const sortedStatistics = statistics.sort((a, b) => {
      if (sortOrder === 'asc') {
        return a.num_cars - b.num_cars;
      } else {
        return b.num_cars - a.num_cars;
      }
    });
  
    return (
      <Container>
        <h1>Owners and Cars</h1>
        <p>Here we have owners ordered by the number of cars they have</p>
        {loading && <CircularProgress />}
        {!loading && statistics.length === 0 && <p>No statistic found</p>}
  
        {!loading && statistics.length > 0 && (
          <TableContainer component={Paper}>
            <Table sx={{ minWidth: 650 }} aria-label="simple table">
              <TableHead>
                <TableRow>
                  <TableCell>#</TableCell>
                  <TableCell>Owner</TableCell>
                  <TableCell align="right">
                    <Tooltip title="Sort by number of cars" arrow>
                      <IconButton onClick={handleSortOrderChange}>
                        {sortOrder === 'asc' ? <ArrowUpwardIcon /> : <ArrowDownwardIcon />}
                      </IconButton>
                    </Tooltip>
                    Number of cars
                  </TableCell>
                  <TableCell align="right">Car_Count</TableCell>
                </TableRow>
              </TableHead>
              <TableBody>
                {sortedStatistics.map((statistic, index) => (
                  <TableRow key={statistic.id}>
                    <TableCell>{index + 1}</TableCell>
                    <TableCell>{statistic.name}</TableCell>
                    <TableCell align="right">{statistic.num_cars}</TableCell>
                  </TableRow>
                ))}
              </TableBody>
            </Table>
          </TableContainer>
        )}
      </Container>
    );
  };