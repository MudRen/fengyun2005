inherit ROOM;
void create()
{
	set("short", "血色通道");
	set("long", @LONG
这是条通往天牢的通道，一路上血迹遍地，机关门户，重重叠叠，当真是
插翅难飞。一道铁门后，便是一道钉满了棉絮的木门，其后又是一道铁门，又
是一道钉棉的板门。通道边是一间间牢房，通过锈迹斑驳的铁栏你可以看到一
个个被折磨得不成人形的囚犯，凄厉的惨叫不时入耳。。。
LONG
        );
        
	set("exits", ([
		"westup" : __DIR__"dalao1",
	]));
	
	set("objects", ([
		__DIR__"npc/guard" : 2,
	]) );

	set("item_desc", ([
		"door": "一个生满铁锈的大门，上了一把巨大的铜锁。看上去除了让守卫\n打开门外，唯有硬撞（ｂｕｍｐ）了。。\n",
		"铁门": "一个生满铁锈的大门，上了一把巨大的铜锁。看上去除了让守卫\n打开门外，唯有硬撞（ｂｕｍｐ）了。。\n",
	]) );
	
	set("jinan_prison",1);
	set("no_fly",1);
	set("coor/x",50);
	set("coor/y",10);
	set("coor/z",-10);
        
	setup();
}

void do_open(){
	object room;
	this_object()->set("exits/east",__DIR__"andao2");
	if (!objectp(room=find_object(__DIR__"andao2"))) 
		room=load_object(__DIR__"andao2");

	room->set("exits/west",__DIR__"andao1");
	return;
}


void init()
{
	add_action("do_bump", "bump");
}

int do_bump(string arg){
	object obj;
	
	if (this_object()->query("exits/east")) 
		return notify_fail("铁门已经被打开了。\n");
	if (objectp(obj=present("prison guard",this_object()))) {
		if (obj->query("prison_guard"))
			return notify_fail("有天牢守卫在旁，没办法撞门。\n");
	}
	if (this_player()->query("force_factor")>80 && this_player()->query("force")>80 ){
		message_vision("$N你气聚丹田，大喝一声，硬生生朝铁门撞了过去。 \n",this_player());
		message_vision("铁门在轰隆巨响声中被$N撞开了。 \n",this_player());
		this_player()->add("eff_kee",-(int)(this_player()->query("max_kee")/5));
		this_player()->add("kee",-(int)(this_player()->query("max_kee")/5));
		this_player()->set_temp("last_damage_from","在济南大牢撞门而死。\n");
		this_player()->set("force",0);
		do_open();
	}
	else{
		message_vision("$N大喝一声，鼓足力气朝铁门撞了上去，但铁门却纹丝不动。 \n",this_player());
		message_vision("$N你喉头一甜，一口鲜血喷了出来！ \n",this_player());
		this_player()->add("eff_kee",-(int)(this_player()->query("max_kee")*4/5));
		this_player()->add("kee",-(int)(this_player()->query("max_kee")*4/5));
		this_player()->set_temp("last_damage_from","在济南大牢撞门而死。\n");
		this_player()->set("force",0);
	}
 	return 1;
}

int reset(){
	if (query("exits/east"))
		delete("exits/east");
	::reset();
}