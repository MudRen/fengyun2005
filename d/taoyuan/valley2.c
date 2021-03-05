inherit ROOM;
void create()
{
        set("short", "山谷");
        set("long", @LONG
此处更加靠近潭水，不必下水，站在潭边你就可以清楚的感觉到刺骨的寒意。
潭水碧绿不知有多深，水中有一巨石，水从高处落下冲击在巨石上溅起点点白色的
水花。潭边长满了不知名的花草，一棵小树斜斜地生长在潭水边。
LONG
        );

	set("item_desc", ([
	"pond" : "潭水明澈见底，里面小鱼小虾皆若空游无所依。\n",
	"清潭" : "潭水明澈见底，里面小鱼小虾皆若空游无所依。\n",
//	"巨石" : "巨石的中央在水的冲击形成了一个凹洞。\n",
//	"stone" : "巨石的中央在水的冲击形成了一个凹洞。\n",
	]) );
	
	set("objects", ([	
	__DIR__"obj/tree": 1,
	]) );
    set("resource/water",1);
    set("liquid/container","水潭");
    set("liquid/name","清潭水");
    set("outdoors","taoyuan");
	set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_around", "around");
}

int do_around(string arg)
{
	object me, room;
	int i;
	
	string *rooms = ({"valley", "valley1", "valley2", "valley3"});
	i = random(4);
	me = this_player();
	if(me->is_busy()){
		return notify_fail("你正在忙！\n");
	}
	tell_object(me, "你转来转去，也没找到出口，你迷了路！！\n\n");
    room = find_object(__DIR__ + rooms[i]);
	if(!objectp(room)) room=load_object(__DIR__ + rooms[i]);
	me->move(room);

	return 1;
}

void reset ()
{
    object *inv;
    object item1, tree;
    ::reset();
    
    tree = present("tree", this_object());
   	inv = all_inventory(tree);
   	if( !sizeof(inv)) {
    	item1 = new(__DIR__"obj/petal");
       	item1->move(tree);
   }   
}

void fish_notify(object obj){
   	object me, room, fish, *inv, bait;
	int i;
	
   	me = this_player();
	inv = all_inventory(obj);
	if(sizeof(inv) == 0){
		message("vision",me->name() + "掏出了" + obj->name() + "又放了回去。\n", environment(me), me);
     	tell_object(me, obj->name() + "上没有饵怎么可以钓鱼呢 ? \n");		
		return;
	}		
	for(i=0; i<sizeof(inv); i++) {
		if(inv[i]->query("fish_bait")) {
			bait = inv[i];
      		message_vision("$N挥动了一下," + obj->name() + "在空中划了一道漂亮的弧线, 鱼钩落入了水中. \n" , me);
      		me->start_busy(5);
      		remove_call_out("do_fishing");              
      		call_out("do_fishing", 5, me, bait);			
			return;
		} 
	}
   	tell_object(me, "你用的饵不太对吧 ? \n");			
	return;
}

void do_fishing(object me, object bait){
	object 	fish;

   	if(me && environment(me) == this_object()) {
   		message_vision("$N很快又扯动了一下鱼杆, " , me);
   		switch (random(3)) {
      	case 0:
         	message_vision("却什么都没钓上来 ! \n", me);
         	break;
      	case 1:
        	message_vision("什么都没钓上来 , 鱼饵却被鱼吃了 !!  \n", me);
			destruct(bait);				
         	break;
      	case 2:
			if (bait->name() == "蚯蚓" && NATURE_D->get_season() == 1 && !NATURE_D->is_daytime() && random(10)<1){        
         		message_vision("鱼钩上钓到一条五色小鱼 !!  \n", me);
         		fish = new(__DIR__"obj/rainbowfish");
         		fish->move(me);
         	} else {      
	        	message_vision("鱼钩上钓到一条大鱼 !!  \n", me);
         		fish = new(__DIR__"obj/fish");
         		fish->move(me);
         	}
         	destruct(bait);
         	break;
      }
   }
   return;
}
