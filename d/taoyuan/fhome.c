inherit __DIR__"no_killing_place";
string garden();
void create()
{
        set("short", "渔家");
        set("long", @LONG
简陋的宅院收拾得十分干净，土坯搭成的墙围成一个四方行的院子，院子中央
搭着一个木架，一席破旧的渔网搭在架子上，架子的旁边是一张木凳和一个用藤条
编成的小针线篮。靠近围墙的地方有一小洼蔬菜地，里面种着些青菜。  
LONG
        );

    set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"road1",
	]) );

	set("item_desc", ([
		"蔬菜地" : (: garden :),
		"garden" : (: garden :),
	]) );
	set("objects", ([
  		__DIR__"obj/basket": 1,
  		__DIR__"npc/caier": 1,
   		__DIR__"obj/stool":1,
   	]) );
   	set("veg_amount", 3);
    set("no_magic", 1);
    set("outdoors","taoyuan");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}

string garden(){
	object me;
	int i;
	me = this_player();
	i = NATURE_D->get_season();
	if(i == 1 && query("veg_amount") > 0) {
		message_vision("蔬菜地里长着些青嫩的毛豆。\n", me);
	} else if(i == 2 && query("veg_amount") > 0){
		message_vision("碧绿的小油菜开着金黄色的花朵。\n", me);
	} else if(i == 3 && query("veg_amount") > 0){
		message_vision("青青的小葱个个水灵灵的。\n", me);
	} else if(i == 4 && query("veg_amount") > 0){
		message_vision("干枯的藤架上挂着几个冬瓜。\n", me);
	} else {
		message_vision("菜洼里是一些凌乱的蔬菜。\n", me);
		return "";
	}
	tell_object(me, "你也许可以采摘一些蔬菜。（ｐｉｃｋ　ｖｅｇ）\n");
	add_action("do_pick", "pick");
	return "";
}

int do_pick(string arg){
	object me, veg;
	int i;
	
	me = this_player();
	i = NATURE_D->get_season();
	if(!arg || arg != "veg"){
		return notify_fail("你要摘什么？\n");
	}
	if(query("veg_amount") > 0){
		message_vision("$N从菜洼里拔了些蔬菜放入怀中。\n", me);
		if(i == 1) {
			veg = new(__DIR__"obj/soybean");
		} else if(i == 2){
			veg = new(__DIR__"obj/youcai");
		} else if(i == 3){
			veg = new(__DIR__"obj/greenorion");
		} else if(i == 4){
			veg = new(__DIR__"obj/donggua");
		}
		add("veg_amount", -1);
		veg->move(me);
	} else {
		return notify_fail("菜洼里已经没有菜了。\n");
	}
	return 1;
}

void reset()
{
    	object *inv;
    	object item1, item2, basket, stool, item3;
    	::reset();
    	
    	basket = present("basket", this_object());
    	if (!present("suo zi",basket))
   		item2 = new(__DIR__"obj/suozi");
   	if (!present("string",basket))	
   		item1 = new(__DIR__"obj/yuxian");
        if (item1) item1->move(basket);
        if (item2) item2->move(basket);
    	
	stool = present("stool", this_object());
	if (!present("fish tank",stool))    
       		item3 = new(__DIR__"obj/fishtank");
        if (item3) item3->move(stool);
        set("veg_amount", 3);
}

