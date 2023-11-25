import 'package:lab_non_native2/car_widget.dart';
import 'package:flutter/widgets.dart';

import 'car_database.dart';
import 'car_entity.dart';

class CarsRepository with ChangeNotifier {
  final List<CarWidget> _items = [];
  final CarsDatabase _carsDatabase = CarsDatabase();

  List<CarWidget> get items => _items;

  CarsRepository() {
    initDatabase();
  }

  initDatabase() async {
    var res = await _carsDatabase.getAllItems();
    for (final item in res) {
      int id = int.parse(item["id"].toString());
      String make = item["make"].toString();
      String model = item["model"].toString();
      DateTime yearOfRegistration = DateTime.parse(item["yearOfRegistration"].toString());
      DateTime nextService = DateTime.parse(item["nextService"].toString());
      DateTime payTax = DateTime.parse(item["payTax"].toString());
      final Car newsItem = Car(
          id: id,
          make: make,
          model: model,
          yearOfRegistration: yearOfRegistration,
          nextService: nextService,
          payTax: payTax);
      CarWidget carWidget = CarWidget(entity: newsItem);
      _items.add(carWidget);
    }
    notifyListeners();
  }

  void addCars(Car item) {
    _carsDatabase.insertCars(item);
    CarWidget carWidget = CarWidget(entity: item);
    _items.add(carWidget);
    notifyListeners(); // Notify listeners when the data changes
  }

  void deleteCarsByIndex(int index) {
    CarWidget card = _items.removeAt(index);
    _carsDatabase.deleteCars(card.entity.id);
    notifyListeners();
  }

  void deleteCarsByInstance(CarWidget carWidget) {
    items.remove(carWidget);
    _carsDatabase.deleteCars(carWidget.entity.id);
    notifyListeners();
  }

  void updateCars(CarWidget oldCard, Car newItem) {
    CarWidget newsCard = CarWidget(entity: newItem);
    _items[_items.indexOf(oldCard)] =
        newsCard; // Update the item at the specified index
    _carsDatabase.updateCars(oldCard.entity.id, newItem);
    notifyListeners();
  }

  CarWidget getCars(int index) {
    return _items[index];
  }

  List<CarWidget> getAllCars() {
    return _items;
  }

  int getLength() {
    return _items.length;
  }
}