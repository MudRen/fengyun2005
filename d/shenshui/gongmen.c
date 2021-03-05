// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "白水宫门");
        set("long", @LONG
湖并没你想象中的那么深，你可以很清楚的看清湖底的一切，湖底长满了各色
的珊瑚和贝壳类生物，在这中间有一个美丽的侗体，身上竟然没有丝毫衣饰，你不
由的转移了你的视线。不远处有一个石洞，洞上用珍珠拼成四个字＂水宫之门＂。
LONG
        );
   	set("exits", ([ 
      		"enter" : __DIR__"gongnei",
      		"up" : __DIR__"lake",
   	]));
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",10);
	set("underwater",50);
	set("water_damage",10);
	setup();
}

void init()
{
	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
}

/*
int do_air(object ob) 
{
   object *inv;
   int	i, da;

   	if (environment(ob)) == this_object()
   inv = all_inventory(this_object());
   if(sizeof(inv) == 0) return 1;
   for(i=0;i<sizeof(inv);i++) {
      if(userp(inv[i])) {
         tell_object(inv[i], "你只觉的胸口发闷，还是快点离开这儿吧。\n");
         da = 50000 / (inv[i]->query("max_force")+1);
         if(da>100) da = 50;
         if(da<10) da = 10;
         inv[i]->receive_damage("kee", da); 
         inv[i]->set_temp("last_damage_from","在白水湖不慎淹死了。\n");
      }
   }
   call_out("do_air", 5+random(10), this_object());
}
*/

