import 'package:flutter/material.dart';
import 'package:lab_non_native2/car_entity.dart';
import 'package:lab_non_native2/car_repository.dart';
import 'package:lab_non_native2/car_widget.dart';
import 'package:provider/provider.dart';

class UpdatePage extends StatefulWidget {
  const UpdatePage(
      {super.key, required this.repository, required this.carWidget});

  final CarsRepository repository;
  final CarWidget carWidget;

  @override
  UpdatePageState createState() => UpdatePageState();
}

class UpdatePageState extends State<UpdatePage> {
  late TextEditingController makeController;
  late TextEditingController modelController;
  late TextEditingController yearOfRegistrationController;
  late TextEditingController nextServiceController;
  late TextEditingController payTaxController;

  @override
  void initState() {
    super.initState();

    // Initialize controllers with existing data
    makeController = TextEditingController(text: widget.carWidget.entity.make);
    modelController =
        TextEditingController(text: widget.carWidget.entity.model);
    yearOfRegistrationController = TextEditingController(
        text: widget.carWidget.entity.yearOfRegistration.toIso8601String());
    nextServiceController =
        TextEditingController(text: widget.carWidget.entity.nextService.toIso8601String());
    payTaxController =
        TextEditingController(text: widget.carWidget.entity.payTax.toIso8601String());
  }

  void _updateInRepository() {
    Car updatedItem = Car(
      make: makeController.text,
      model: modelController.text,
      yearOfRegistration: DateTime.parse(yearOfRegistrationController.text),
      nextService: DateTime.parse(nextServiceController.text),
      payTax: DateTime.parse(payTaxController.text),
    );

    Provider.of<CarsRepository>(context, listen: false)
        .updateCars(widget.carWidget, updatedItem);
    Navigator.pop(context);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Update Page'),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            TextField(
              controller: makeController,
              decoration: const InputDecoration(labelText: 'Title'),
            ),
            TextField(
              controller: modelController,
              decoration: const InputDecoration(labelText: 'Content'),
            ),
            TextField(
              controller: yearOfRegistrationController,
              decoration: const InputDecoration(labelText: 'Year of Registration Date (YYYY-MM-DD)'),
            ),
            TextField(
              controller: nextServiceController,
              decoration: const InputDecoration(labelText: 'Next Service'),
            ),
            TextField(
              controller: payTaxController,
              decoration: const InputDecoration(labelText: 'Taxes'),
            ),
            const SizedBox(height: 16),
            ElevatedButton(
              onPressed: _updateInRepository,
              child: const Text('Update'),
            ),
          ],
        ),
      ),
    );
  }
}