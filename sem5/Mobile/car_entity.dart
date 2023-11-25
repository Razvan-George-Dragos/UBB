class Car {
  final int id;
  final String make;
  final String model;
  final DateTime yearOfRegistration;
  final DateTime nextService;
  final DateTime payTax;

  Car({
    this.id = -1,
    required this.make,
    required this.model,
    required this.yearOfRegistration,
    required this.nextService,
    required this.payTax,
  });
}