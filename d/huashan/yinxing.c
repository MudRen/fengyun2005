#include <ansi.h>
inherit ROOM;
string tree();
string vine();
void create()
{
        set("short", "银杏溪边");
        set("long", @LONG
溪流不宽，紧挨小溪生长着一棵巨大的银杏树，树粗有数合抱，树冠如盖十分
茂密，紫红色的古藤如龙似蛇盘饶树身。树旁杂草灌木丛生，仔细看隐约可辨一条
布满荆棘的小路伸向东北方。
LONG
        );
    set("exits", ([ 
		"northeast" : __DIR__"meigu",
	]));
	set("item_desc", ([
		"小溪" : "小溪不宽，河水清澈。你可以跃过去。（ｄａｓｈ）。\n",
		"stream" : "小溪不宽，河水清澈。你可以跃过去。（ｄａｓｈ）。\n",
		"tree" : (: tree :),
		"银杏树" : (: tree :),
		"vine" : (: vine :),
		"古藤" : (: vine :),
	]));   
	set("leaf_amount", 10);
	set("baiguo_amount", 5);
	set("have_snake", 1);
	set("have_herb", 1);
    set("outdoors", "huashan");

	set("coor/x",-5);
	set("coor/y",-50);
	set("coor/z",30);
	setup();
}

void init(){
	add_action("do_dash", "dash");
}

string vine(){
	object me;
	int i;
	me = this_player();
	i = NATURE_D->get_season();
	if(i == 4) {
		tell_object(me, "古藤紧紧缠绕在树干上，好像拥抱在一起的情人。\n");
	} else {
		tell_object(me, "古藤紧紧缠绕在树干上，好像拥抱在一起的情人。\n");
		if(me->query_skill("herb", 1) >=100 && query("have_herb")) {
			tell_object(me, "你注意到古藤旁的一棵不起眼的小草。（ｐｉｃｋ）\n");
			add_action("do_pick", "pick");
		}
		if(!random(10) && query("have_snake") && (i == 2 || i ==3)){
			tell_object(me, "你似乎看到一断紫红色的古藤蠕动了一下，但又好似自己眼花。\n");
			call_out("snake_come", 10, me);
		}
	}
	return "";
}

void snake_come(object me){
	object obj;
	if(!interactive(me) || environment(me) != this_object()){
		return;
	}
	message_vision(MAG"\n一条全身紫红色的小蛇从古藤中游走了出来。\n"NOR, me);
	obj = new(__DIR__"npc/snake");
	obj -> move(this_object());
	set("have_snake", 0);
	call_out("snake_leave", 10);
}

void snake_leave(){
	object obj;
	if(obj = present("little snake", this_object())){
		message_vision("小蛇缓缓游入古藤中。\n", obj);
		set("have_snake", 1);
		destruct(obj);
	}
}

string tree(){
	object me;
	int i;
	me = this_player();
	i = NATURE_D->get_season();
	if(i == 1 || i == 2){
		tell_object(me, "碧绿色树冠着挡住了天空，扇形的树叶在微风中摇曳（ｐｉｃｋ　ｌｅａｆ）。\n");
		add_action("do_pick", "pick");
	} else if(i == 3){
		if(query("baiguo_amount") > 0) {
			tell_object(me, "满树的金黄让人挪不开目光，金黄中点缀着白色的果实（ｐｉｃｋ　ｂａｉｇｕｏ）。\n");
			add_action("do_pick", "pick");
		} else {
			tell_object(me, "满树的金黄让人挪不开目光。\n");
		}
	} else if(i == 4){
		tell_object(me, "光秃的树干透着银白色，显得虬劲有力。\n");
	}
	return "";
}

int do_pick(string arg){
	object me, obj;
	int i;
	me = this_player();
	if(!arg || (arg != "leaf" && arg != "baiguo" && arg != "果实" && arg != "叶"
			&& arg != "grass" && arg != "小草")){
		return 0;
	}
	i = NATURE_D->get_season();
	
	if((i == 1 || i == 2) && query("leaf_amount") > 0 && (arg == "leaf" || arg == "叶")){
		message_vision("$N垫脚从树上摘下一片叶子。\n", me);
		obj = new(__DIR__"obj/leaf"); 
		if(objectp(obj)){
			obj->move(me);
		}
		add("leaf_amount", -1);
		return 1;
	} else if(i == 3 && query("baiguo_amount") > 0 && (arg == "baiguo" || arg == "果实")) {
		message_vision("$N探手摘下一颗白色的果实。\n", me);
		obj = new(__DIR__"obj/ginkgo");
		if(objectp(obj)){
			obj->move(me);
		}
		add("baiguo_amount", -1);	
		return 1;
	}
	if(query("have_herb") > 0 && (arg == "grass" || arg == "小草")) {
		message_vision("$N探手拔下棵毫不起眼的小草。\n", me);
		obj = new(__DIR__"obj/herb");
		if(objectp(obj)){
			obj->move(me);
		}
		add("have_herb", -1);
		return 1;
	}
	tell_object(me, "已经被摘完了。\n");
	return 1;
}

int do_dash(){
	object me, room;
	
	me = this_player();
	message_vision("$N退后两步，猛然加快脚步一个纵身轻盈的越过了小溪。\n", me);
	room = find_object(__DIR__"xiaodao1");
	if(!objectp(room)){
		room = load_object(__DIR__"xiaodao1");
	}
	me->move(room);
	message("vision", me->name() + "从小溪的另外一边跃了过来。\n", environment(me), me);
	return 1;
}

void reset(){
	::reset();
	set("baiguo_amount", 5);
	set("leaf_amount", 10);
	set("have_snake", 1);
	set("have_herb", 1);
}
