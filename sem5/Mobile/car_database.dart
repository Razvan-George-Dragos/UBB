import 'package:flutter/cupertino.dart';
import 'package:path/path.dart';
import 'package:sqflite_common_ffi/sqflite_ffi.dart';
import 'package:path_provider/path_provider.dart';
import 'car_entity.dart';
import 'dart:io';

class CarsDatabase {
  static Database? _database;
  final String _tableName = "cars";

  CarsDatabase() {
    initDatabase();
  }

  Future<Database> get database async {
    _database ??= await initDatabase();
    return _database!;
  }

  Future<Database> initDatabase() async {
    WidgetsFlutterBinding.ensureInitialized();
    final Directory appDocumentsDir = await getApplicationDocumentsDirectory();

    // Get the path to the database
    String path =
    join(appDocumentsDir.path, "databases", "cars_database.sqlite");
    print("PATH ==================== $path");

    sqfliteFfiInit();

    var databaseFactory = databaseFactoryFfi;
    var db = await databaseFactory.openDatabase(path);
    await db.execute('''
      CREATE TABLE IF NOT EXISTS cars (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            make TEXT,
            model TEXT,
            yearOfRegistration DATETIME,
            nextService DATETIME,
            payTax DATETIME
          );
    ''');

    return db;
  }

  Future<List<Map<String, Object?>>> getAllItems() async {
    var db = await database;
    return db.query(_tableName);
  }

  Future<void> insertCars(Car item) async {
    final db = await database;
    db.insert(_tableName, {
      "make": item.make,
      "model": item.model,
      "yearOfRegistration": item.yearOfRegistration.toString(),
      "nextService": item.nextService.toString(),
      "payTax": item.payTax.toString()
    });
  }

  Future<void> deleteCars(int index) async {
    if (index == -1) {
      // TREAT ERROR
    } else {
      final db = await database;
      db.delete(_tableName, where: "id=$index");
    }
  }

  Future<void> updateCars(int index, Car item) async {
    if (index == -1) {
      // TREAT ERROR
    } else {
      final db = await database;
      db.update(_tableName, {
        "make": item.make,
        "model": item.model,
        "yearOfRegistration": item.yearOfRegistration.toString(),
        "nextService": item.nextService.toString(),
        "payTax": item.payTax.toString()
      }, where: "id=$index");
    }
  }
}