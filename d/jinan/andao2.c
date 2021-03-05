inherit ROOM;
void create()
{
	set("short", "血色通道");
	set("long", @LONG
这是条通往天牢的通道，一路上血迹遍地，机关门户，重重叠叠，当真是
插翅难飞。一道大铁门后，有一道钉满了棉絮的木门通往地牢，另一道钉棉的
铁门东首便是天牢重地。通道边是一间间牢房，通过锈迹斑驳的铁栏你可以看
到一个个被折磨得不成人形的囚犯，凄厉的惨叫不时入耳。。。
LONG
        );
        
	set("exits", ([ /* sizeof() == 4 */
		//"west" : __DIR__"andao1",
		//"east" : __DIR__"prison",
		//"southdown" : __DIR__"prison2",
	]));

	set("objects", ([
		__DIR__"npc/guard2" : 1,
		__DIR__"npc/guard1" : 1,
	]) );

	set("item_desc", ([
		"wooddoor": "一扇上着大铁锁的木门，可以用钥匙打开（ｕｎｌｏｃｋ）。\n",
		"木门": "一扇上着大铁锁的木门，可以用钥匙打开（ｕｎｌｏｃｋ）。\n",
        "铁门": "一扇上着大铁锁的铁门，可以用钥匙打开（ｕｎｌｏｃｋ）。\n",
        "irondoor": "一扇上着大铁锁的铁门，可以用钥匙打开（ｕｎｌｏｃｋ）。\n",
	]) );
        
	set("no_fly",1);
	set("jinan_prison",1);
	set("coor/x",60);
	set("coor/y",10);
	set("coor/z",-10);
	
	setup();
}

void do_kill(object ob)
{
	int i;
	object *inv;
	
	inv=all_inventory(this_object());
	for (i=0;i<sizeof(inv);i++){
		if (inv[i]->query("prison_guard"))
			inv[i]->do_alert(ob);
	}
	return;
}

void do_open1(){
	object room;
	this_object()->set("exits/east",__DIR__"prison");
	if (!objectp(room=find_object(__DIR__"prison"))) 
		room=load_object(__DIR__"prison");

	room->set("exits/west",__DIR__"andao2");
	return;
}

void do_open2(){
	object room;
	this_object()->set("exits/southdown",__DIR__"prison2");
	if (!objectp(room=find_object(__DIR__"prison2"))) 
		room=load_object(__DIR__"prison2");

	room->set("exits/northup",__DIR__"andao2");
	return;
}

void do_open(){
	if (random(2) && !query("exits/east"))
		do_open1();
	else
		do_open2();
	return;
}

void init()
{       
	if(!this_player()->query_temp("show_order") && userp(this_player())) {
		do_kill(this_player());
	}
	add_action("do_unlock", "unlock");
}

int do_unlock(string arg){
	object ob,room;
	if (!objectp(ob=present("key",this_player())))
		return notify_fail("你身上没有钥匙。\n");
	if (!ob->query("prison_key"))
		return notify_fail("你身上没有合用的钥匙。\n");
	if (arg!="木门" && arg!="wooddoor" && arg!="铁门" && arg!="irondoor")
		return notify_fail("你要打开哪一扇门？\n");
	if ((arg=="木门" || arg=="wooddoor") && this_object()->query("exits/southdown"))
		return notify_fail("木门已经被打开了。\n");
	if ((arg=="铁门" || arg=="irondoor") && this_object()->query("exits/east"))
		return notify_fail("铁门已经被打开了。\n");	
	message_vision("$N将钥匙插入锁孔，用力一拧，大门嘎吱一声，开了。\n但钥匙却因用力过大，叭答一下断了。\n",this_player());
	ob->set("name","断了的"+ob->query("name"));
	ob->set("prison_key",0);
	if (arg=="木门" || arg=="wooddoor"){
		//"southdown" : __DIR__"prison2",
		do_open2();
	}
	if (arg=="铁门" || arg=="irondoor"){
		//"east" : __DIR__"prison",
		do_open1();
	}
	return 1;
	
}


int reset(){
	
	if (query("exits/southdown"))
		delete("exits/southdown");
		
	if (query("exits/east"))
		delete("exits/east");
	::reset();
}