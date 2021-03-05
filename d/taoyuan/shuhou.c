#include <ansi.h>
inherit __DIR__"no_killing_place";
void create()
{
	
	set("short", "草坪");
        set("long", @LONG
梧桐树后俨然一方小小天空，宽大的梧桐树叶湿润绿厚，叶叶心心、舒卷有馀
情，微风中徐徐摆动。一张石桌，两个石凳端端正正地摆在小草坪中央，小河无声
无息地从你身旁绕了个圈儿流过，一股清新的凉风从河面上吹来，你不由得觉得精
神为之一振，一句不知何人的诗涌入脑中：落叶流水杳然去 别有天地非人间 ．．
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"grassland",
	]) );
	set("objects", ([
		"/obj/item/stool" : 2,
	]));
	set("item_desc", ([
           "river" : "一条清澈的小河，河里有小鱼在游动。\n",
           "小河" : "一条清澈的小河，河里有小鱼在游动。\n",

	]) );
	set("no_magic", 1);
	set("outdoors","taoyuan");
    set("stools", 3);
	set("coor/x",30);
	set("coor/y",40);
	set("coor/z",0);
	setup();

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

void do_fishing(object me, object bait)
{
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
         message_vision("鱼钩上钓着一条大鱼 !!  \n", me);
         fish = new(__DIR__"obj/fish");
         fish->move(me);
         destruct(bait);
         break;
      }
   }
   return;
}

/*int do_sitdown(){
	
	object me;
	mapping who;
	int i,j,amount;
	
	me = this_player();
	
	amount=query("stools");
	j=-1;
	for(i=0;i<amount;i++)
	{
		if(me==query("sitdown_person/"+(string)i)) return  notify_fail("你已经坐下了呀！？\n");		
		if(query("sitdown_person/"+(string)i)&&present(query("sitdown_person/"+(string)i),this_object())) {}
		else j=i;
	}
	if(j==-1)	return notify_fail("石凳上都已经坐满了人。。。\n");
	message_vision("$N在石桌边的石凳上坐了下来。\n", me);
	set("sitdown_person/"+(string)j,me);
		
	
	return 1;
}

int do_standup()
{
	object me;
	int i,amount;
	mapping who;
	

	me=this_player();
	amount=query("stools");
	for(i=0;i<amount;i++)
	{	
		if(me==query("sitdown_person/"+(string)i))
		{
			message_vision("$N从石凳上站起身来。\n",me);
			set("sitdown_person/"+(string)i,0);
			return 1;
		}
	}
	return 0;
}*/

int valid_leave(object who,string dir){
	int i;
	mixed *inv;
	object stool;
	inv = all_inventory(this_object());
	for (i=0; i<sizeof(inv); i++){
		if(who == inv[i]->query("sitdown_person")){
			return notify_fail("你正坐着呢，不能离开！！\n");
		}
	}
	return ::valid_leave(who,dir);
}

int invalid_leave(object player) {
	object *stool_list;
	object stool;
	stool_list = children("/obj/item/stool");
	for(int i=0; i<sizeof(stool_list); i++)
	{
		stool = stool_list[i];
		if (present(stool,this_object()))
		{
			if (player->query_temp("state/sit") && (stool->query("sitdown_person")==player))
			{
				//stool->set("long","石凳的表面被磨得十分光滑，看来经常有人坐在这里（ｓｉｔｄｏｗｎ）。\n");
				stool->delete("sitdown_person");
				player->delete_temp("state/sit");
			}	
		}
	}
    return 0;
}
