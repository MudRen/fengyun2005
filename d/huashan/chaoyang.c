
inherit ROOM;

void create()
{
        set("short", "朝阳峰");
        set("long", @LONG
此峰位于华山五峰之东，向上看整个山峰顶部犹如一块巨大的岩石，光秃秃的
石壁之上毫无树枝藤蔓可以攀援，石壁上只有几个凿出的足窝，所以攀登的人必须
手脚并用才能达到峰巅。向东南望有一座孤峰掩映在云海之中。
LONG
        );
    set("exits", ([ 
  		"northwest" : __DIR__"xiaodao1",
	    "southeast" : __DIR__"yaozi",
	    "southdown" : __DIR__"ziqi",
	]));
   
   		set("item_desc", ([
 		"石壁": "石壁陡峭，上面只有几个凿出的足窝。\n",
   		"cliff": "石壁陡峭，上面只有几个凿出的足窝。\n",
 	]) );  
   		
    set("outdoors", "huashan");

	set("coor/x",-4);
	set("coor/y",-53);
	set("coor/z",33);
	setup();
}

void init(){
    add_action("do_climb", "climb");
}

int do_climb(string arg){
    object me;
    
    me = this_player();
    if(!arg || arg == "") {
        return notify_fail("你要爬什么？\n");
    }
    if(me->is_busy()) {
        return notify_fail("你正在忙。\n");
    }
    if(arg == "up" || arg == "cliff"  || arg == "石壁" ) {
        message_vision("$N手脚并用，身子紧贴着石壁，慢慢向上爬去。\n", me);
        me->start_busy(3);
        call_out("fliping", 3, me);
    } 
    return 1;
}

int fliping(object me){   
    object ob;
	
    ob = find_object(__DIR__"cytop");
    if(!objectp(ob)){
	    ob = load_object(__DIR__"cytop");
	}
    me->move(ob);
    message_vision("$N顺着崖壁爬了上来。\n", me);
    return 1;
}
