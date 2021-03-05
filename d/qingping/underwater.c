//XXDER
inherit ROOM;
void create()
{
        set("short", "水下");
        set("long", @LONG
水不冷，鱼虾依然悠闲地在你身边游来荡去，裹住你双腿的水草由于你用力的
挣扎而松落了。水很清，借着从水上透过来的光线，你看到身旁一堆水草的下面露
出一块磨盘大小的石头，石头的四周是白色的沙子。
LONG
        ); 
   set("exits", ([ /* sizeof() == 4 */
       "up" : __DIR__"northpond",
   ]));

   set("item_desc", ([
      "stone" : "洁白的石头有人工琢磨过的痕迹，但上面长满了水草。 \n",
      "石头" : "洁白的石头有人工琢磨过的痕迹，但上面长满了水草。 \n",
   ]) );
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",-20);
   setup();
	
}

void init()
{
   	add_action("do_push", "push");
}

int do_push(string arg)
{
   	object me,room;

   	me = this_player();
   	if (!arg || (arg != "stone" && arg != "石头"))
      		return 0;
   	if (me->query_temp("marks/opened")) {
      	message_vision("\n\n$N伸手向石头推去，石头随着你手上的力道向一边滑开。\n",me);
      	message_vision("\n\n湖中的水突然向石后的空洞涌去！$N的头被水流带动，狠狠地撞在了石头上！\n\n\n",me);
   		me->set_temp("marks/guest", 1);
        me->unconcious();
   		room = find_object(AREA_SHENSHUI"woshi2");
   		if(!objectp(room)) room=load_object(AREA_SHENSHUI"woshi2");
   		me->move(room);
   		me->set("marks/enter_ss/钓鱼",1);  
   	}
   	else
   		message_vision("$N使出浑身的力气，石头还是纹丝不动。\n",me);
   	return 1;
}
