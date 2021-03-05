// 地道
inherit ROOM;
void create()
{
        set("short", "地道");
        set("long", @LONG
黑漆漆的地道，你不知道要爬多久才能出去。
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"didao",
  "westdown" : __DIR__"didao2",
]));
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",-40);
	setup();
}
int valid_leave(object me, string dir)
{
        if( userp(me) )
                    message_vision("$N手脚并用，向地道深处爬去\n",me);

        return 1;
}
void init()
{
	add_action("do_go","go");

}

int do_go()
   {
   if(random(5)){
     message_vision("$N手脚并用，向地道深处爬去\n",this_player());
     this_player()->move(this_object());
     return 1;
   }
}

