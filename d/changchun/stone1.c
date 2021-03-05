
inherit ROOM;
void create()
{
	object ob;
	object table;
	set("short", "石屋");
	set("long", @LONG
走着走着，秘道中忽然亮起了灯光。前面岩壁，已被凿成石灯的模样，灯蕊竟
有十余条之多，互相连接。秘道中一直是阴湿而黝暗，这里却是干燥宽敞，左面一
张石床，右面一张石桌，几张石凳。石桌旁还有个石盆，盆沿雕成双龙抢珠之势，
一缕清泉，潺潺不绝，自龙口流了出来，又自盆底流了出去，盆中却始终保持着满
盆清水。
LONG
	);
	set("exits",([
		"west" :__DIR__"hole",
		"down" :__DIR__"stone2",
	]) );
	set("objects",([
		AREA_TIEFLAG"npc/yedi" : 1,
      		AREA_TIEFLAG"obj/table" : 1,
	]) );
	set("resource/water",1);
    	set("liquid/name","清泉水");
    	set("liquid/type", "water");
    	set("liquid/drunk_apply",6);

	set("coor/x",90);
	set("coor/y",-20);
	set("coor/z",-20);
	setup();
}

void reset()
{
	object ob,yedi,table;
	object *inv;
	int i;
	::reset();
	if (yedi=present("ye di",this_object()))
		yedi->delete_temp("marks/gived_reward");
	if (table=present("table",this_object()))
	{
		inv=all_inventory(table);
                for(i=0;i<sizeof(inv);i++)
			if (inv[i]->query("id")=="powder") 
				destruct(inv[i]);
		for(i=0;i<3;i++)
		{
			ob=new(AREA_TIEFLAG"obj/powder");
			ob->move(table);			
		}
	}
}	
	 
