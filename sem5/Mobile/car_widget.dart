import 'package:flutter/material.dart';
import 'package:lab_non_native2/car_entity.dart';
import 'package:lab_non_native2/update_cars.dart';
import 'package:provider/provider.dart';

import 'car_repository.dart';


class CarWidget extends StatefulWidget {
  final Car entity;

  const CarWidget({super.key, required this.entity});

  @override
  CarWidgetState createState() => CarWidgetState();
}

class CarWidgetState extends State<CarWidget> {
  bool isExpanded = false;

  void _openUpdatePage() {
    Navigator.push(
      context,
      MaterialPageRoute(
        builder: (context) => UpdatePage(
            repository: Provider.of<CarsRepository>(context, listen: false),
            carWidget: widget),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Card(
      elevation: 3,
      margin: const EdgeInsets.all(10),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: <Widget>[
          Row(
            children: [
              Expanded(
                child: ListTile(
                  title: Text(
                    widget.entity.make,
                    style: const TextStyle(
                      fontWeight: FontWeight.bold,
                      fontSize: 18,
                    ),
                  ),
                  subtitle: Text(
                    "Model: ${widget.entity.model}",
                    style: const TextStyle(
                      fontSize: 14,
                    ),
                  ),
                ),
              ),
              ElevatedButton(
                onPressed: () {
                  setState(() {
                    isExpanded = !isExpanded;
                  });
                },
                child: Text(isExpanded ? "Collapse" : "Expand"),
              ),
            ],
          ),
          if (isExpanded)
            Padding(
              padding: const EdgeInsets.all(10),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Text(
                    widget.entity.model,
                    style: const TextStyle(fontSize: 16),
                  ),
                  ListTile(
                    leading: const Icon(Icons.source),
                    title: Text("Year Of Registration: ${widget.entity.yearOfRegistration.toLocal()}"),
                  ),
                  ListTile(
                    leading: const Icon(Icons.category),
                    title: Text("Next Service: ${widget.entity.nextService}"),
                  ),
                  ListTile(
                    leading: const Icon(Icons.image),
                    title: Text("Taxes: ${widget.entity.payTax.toLocal()}"),
                  ),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [
                      ElevatedButton(
                        onPressed: () {
                          _openUpdatePage();
                        },
                        child: const Text("Update"),
                      ),
                      ElevatedButton(
                        onPressed: () {
                          isExpanded = false;
                          Provider.of<CarsRepository>(context, listen: false)
                              .deleteCarsByInstance(widget);
                        },
                        style: ElevatedButton.styleFrom(
                          backgroundColor: Colors.red,
                        ),
                        child: const Text("Delete"),
                      ),
                    ],
                  ),
                ],
              ),
            ),
        ],
      ),
    );
  }
}