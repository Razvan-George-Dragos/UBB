import 'package:flutter/material.dart';
import 'package:lab_non_native2/car_entity.dart';
import 'package:lab_non_native2/car_repository.dart';
import 'package:provider/provider.dart';

class AddPage extends StatefulWidget {
  const AddPage({super.key, required this.repository});

  final CarsRepository repository;

  @override
  AddPageState createState() => AddPageState();
}

class AddPageState extends State<AddPage> {
  final TextEditingController makeController = TextEditingController();
  final TextEditingController modelController = TextEditingController();
  final TextEditingController yearOfRegistrationController = TextEditingController();
  final TextEditingController nextServiceController = TextEditingController();
  final TextEditingController payTaxController = TextEditingController();

  void _saveToRepository() {
    Car carsItem = Car(
      make: makeController.text,
      model: modelController.text,
      yearOfRegistration: DateTime.parse(yearOfRegistrationController.text),
      nextService: DateTime.parse(nextServiceController.text),
      payTax: DateTime.parse(payTaxController.text),
    );

    Provider.of<CarsRepository>(context, listen: false).addCars(carsItem);
    Navigator.pop(context);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Add Page'),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            TextField(
              controller: makeController,
              decoration: const InputDecoration(labelText: 'Make'),
            ),
            TextField(
              controller: modelController,
              decoration: const InputDecoration(labelText: 'Model'),
            ),
            TextField(
              controller: yearOfRegistrationController,
              decoration: const InputDecoration(labelText: 'Year of Registration (YYYY-MM-DD)'),
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
              onPressed: _saveToRepository,
              child: const Text('Save'),
            ),
          ],
        ),
      ),
    );
  }
}