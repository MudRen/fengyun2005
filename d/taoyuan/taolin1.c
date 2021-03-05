inherit ROOM;
string tree();
void create()
{
        set("short", "桃林");
        set("long", @LONG
这是一片茂密的桃树林，林中芳草鲜美，落英缤纷，一层淡淡的薄雾，混合着
青青的草香，弥漫在空气之中。偶尔的一两声鸟鸣，愈发地显出幽静来。这里的小
路已被落花铺满，早已辨不出痕迹来。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"taolin2",
  "west" : __DIR__"taolin",
]));

	set("item_desc", ([
	    "桃树": (: tree :),
	    "peach tree": (: tree :),
	    "tree" : (: tree :),
	]) );
	set("peach_amount",2);
	set("flower_amount", 1);
   	set("outdoors","taoyuan");
	set("coor/x",-70);
	set("coor/y",10);
	set("coor/z",0);

	setup();
}

string tree(){
	object me;
	int i;
	me = this_player();
	i = NATURE_D->get_season();
	if(i == 1) {
		if(query("flower_amount") > 0) {
			tell_object(me, "缤纷的桃花似彩霞，几个开满粉红色花朵的桃枝在你面前抬手可及的地方。\n");
			add_action("do_pick", "pick");
		} else {
			tell_object(me, "缤纷的桃花似彩霞。\n");
		}
	} else if (i == 2) {
		if(query("peach_amount") > 0) {
			tell_object(me, "树上结满的鲜美的大桃子。\n");
			add_action("do_pick", "pick");
		} else {
			tell_object(me, "在树枝的高处，挂着几个青涩的桃子。\n");
		}
	} else if (i == 3) {
		tell_object(me, "茂密的树叶已经开始发黄了。\n");
	} else {
		tell_object(me, "光秃秃的树枝上什么都没有。\n");
	}
	return "";
}

int do_pick(string arg)
{
   	object me, tao;
	int i;
	
	i = NATURE_D->get_season();
   	me = this_player(); 
   	if(!arg ) return 0;	
   	if (i == 2 && (arg == "peach" || arg == "蜜桃")){
    	if(query("peach_amount") > 0) {
    		tao = new(__DIR__"obj/taozi");
      		tao->move(me);
      		add("peach_amount", -1);
      		message_vision("\n$N伸手摘了一个鲜美的桃子下来。\n", me);
   		} else { 
      		tell_object(me,"桃子都被摘光啦！！！ \n");
    	}
    } else if (i == 1 && (arg == "flower" || arg == "taozhi" || arg == "桃枝")){
    	if(query("flower_amount") > 0) {
    		message_vision("\n$N伸手折下一枝桃花。\n", me);
    		add("flower_amount", -1);
    		tao = new(__DIR__"obj/taozhi");
    		tao->move(me);
    	} else {
    		tell_object(me, "没有花了。\n");
    	}
    } else {
    	return 0;
    }
    return 1;
}
