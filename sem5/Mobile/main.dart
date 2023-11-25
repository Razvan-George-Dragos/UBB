import 'package:flutter/material.dart';
import 'package:lab_non_native2/car_repository.dart';
import 'package:provider/provider.dart';

import 'add_page.dart';

//import 'add_page.dart';

void main() async {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return ChangeNotifierProvider(
      create: (context) => CarsRepository(),
      child: MaterialApp(
        title: 'Cars App',
        theme: ThemeData(
          colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
          useMaterial3: true,
        ),
        home: const MyHomePage(title: 'Cars App'),
      ),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  void _openAddPage() {
    Navigator.push(
      context,
      MaterialPageRoute(
        builder: (context) => AddPage(
            repository: Provider.of<CarsRepository>(context, listen: false)),
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Expanded(child:
            Consumer<CarsRepository>(builder: (context, repository, child) {
              return ListView.builder(
                itemCount: repository.getLength(),
                itemBuilder: (context, index) {
                  return repository.getCars(index);
                },
              );
            })),
          ],
        ),
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: _openAddPage,
        tooltip: 'Increment',
        child: const Icon(Icons.add),
      ),
    );
  }
}