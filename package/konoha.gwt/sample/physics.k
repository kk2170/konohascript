using konoha.gwt.*;

class PhysicsWorld {
	World world;
	Scene scene;
	View view;
	float rotate_duration;
	Transform trans;
	Rect ground;
	Group group;

	PhysicsWorld() {
		scene = new Scene();
		world = new World(scene);
		world.setBeginContactEvent(delegate(this, beginContact));
		world.setEndContactEvent(delegate(this, endContact));
		scene.setSceneRect(0, 0, 600, 600);
		//scene.setBackgroundColor(new Color("black"));
		rotate_duration = 5.0f;
		group = new Group();
	}
	
	void addStaticObject() {
		Color static_block_color = new Color("#90ee90");
		ground = new Rect(200, 400, 200, 40);
		ground.setColor(static_block_color);
		ground.setShadow(new Shadow());
		Rect left_block = new Rect(200, 350, 10, 50);
		//group.addToGroup(ground);
		left_block.setColor(static_block_color);
		//left_block.setShadow(new Shadow());
		Rect right_block = new Rect(400 - 10, 350, 10, 50);
		right_block.setColor(static_block_color);
		right_block.setShadow(new Shadow());
		Ellipse e = new Ellipse();
		e.setRect(new Rect(300, 300, 20, 20));
		e.setColor(new Color("#999900"));
		//e.setGlow();
		Ellipse star = new Ellipe();
		star.setRect(new Rect(400, 200, 40, 40));
		star.setColor(new Color("#00ff00"));
		star.setGlow();
		scene.addItem(star);
		ground.setRestitution(0);
		scene.addItem(ground);
		scene.addItem(left_block);
		scene.addItem(right_block);
		scene.addItem(e);
		world.add(left_block);
		world.add(right_block);
		world.add(ground);
		world.add(e);
	}

	void addDynamicObject() {
		for (int i = 0; i < 100; i++) {
			int r = Int.random(100);
			Rect rect = new Rect(350 - r, 300 - r, 10, 10);
			rect.setDensity(1);
			//rect.setFriction(0.3);
			rect.setRestitution(0.1);
			rect.setColor(new Color("#87ceeb"));//155 - r, 200 - r, 255 - r));
			world.add(rect);
			scene.addItem(rect);
		}
		Ellipse e = new Ellipse();
		e.setRect(new Rect(250, 300, 30, 30));
		e.setColor(new Color("#eeee00"));
		e.setDensity(1.0);
		e.setGlow();
		Text text = new Text("Hello World");
		text.setPosition(300, 100);
		text.setDensity(1.0);
		//Texture texture = new Texture("sample/qt.jpg");
		//texture.setRect(new Rect(200, 200, 50, 50));
		//texture.setDensity(1);
		world.add(e);
		scene.addItem(e);
		world.add(text);
		scene.addItem(text);
		//world.add(texture);
		//scene.addItem(texture);
	}

	void show() {
		view = new View(scene);
		view.setRenderHint(Painter.Antialiasing);
		t = new Timer(1000 / 40, delegate(this, rotate));
		//t.start();
		view.show();
		world.start();
	}

	void rotate(TimerEvent event) {
		//view.rotate(rotate_duration);
		rotate_duration += 5.0;
		trans = new Transform();
		trans.translate(200 + 100, 400 + 20);
		trans.rotate(rotate_duration, Gwt.YAxis);
		//ground.setTransform(trans);
		//group.setTransform(trans);
		//view.setTransform(trans);
	}

	Color getRandomColor() {
		String color = "#";
		for (int i = 0; i < 3; i++) {
			color += "%x"(50 + Int.random(206));
		}
		return new Color(color);
	}

	void beginContact(dynamic obj1, dynamic obj2) {
		//print "beginContact";
		Color color1 = getRandomColor();
		Color color2 = getRandomColor();
		if (obj1.class == Rect) {
			Rect r = (Rect)obj1;
			if (!r.isStatic()) {
				r.setColor(color1);
			}
		} else if (obj1.class == Ellipse) {
			Ellipse e = (Ellipse)obj1;
			e.setColor(color1);
			e.setGlow();
		} else if (obj1.class == Texture) {
			Texture t = (Texture)obj1;
			t.setColor(color1);
		}
		if (obj2.class == Rect) {
			Rect r = (Rect)obj2;
			if (!r.isStatic()) {
				r.setColor(color2);
			}
		} else if (obj2.class == Ellipse) {
			Ellipse e = (Ellipse)obj2;
			e.setColor(color2);
			e.setGlow();
		} else if (obj2.class == Texture) {
			Texture t = (Texture)obj2;
			t.setColor(color2);
		}
	}

	void endContact(dynamic obj1, dynamic obj2) {
		//print "endContact";
		//print obj1.class;
		//print obj2.class;
	}
}

void main(String[] args)
{
	Application app = new Application();
	PhysicsWorld world = new PhysicsWorld();
	world.addStaticObject();
	world.addDynamicObject();
	world.show();
	app.exec();
}
