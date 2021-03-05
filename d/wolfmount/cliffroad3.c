inherit ROOM;

void create()
{
	set("short", "悬崖栈道");

	set("long", @LONG
一条依傍着悬崖峭壁的栈道，弯弯曲曲不知通向何方。抬头往上看去，云雾缭
绕，山气渐浓。身下则是万丈沟壑，深不见底。栈道年久失修，木制护栏断的断，
折的折，一不小心就不免坠入下面的无底深渊，栈道南侧有一个很隐蔽的山洞。
LONG);

	set("type","road");
	set("exits",([
        "west":__DIR__"cliffroad2",
        "enter":__DIR__"chiyoudao",
        "southeast":__DIR__"cliffroad4",
	]) );
       set("outdoors", "wolfmount");
	set("objects",([
     		__DIR__"npc/toutuo":1,
    	]) );
	set("coor/x",40);
	set("coor/y",20);
	set("coor/z",-30);
	set("count",0);
	setup();
}

//	The reset function here is for chiyouku, since chiyouku is a rare-accessed room, the function
//	in that room could be unloaded thus stops working correctly.
//  No need now, we use boss system on chi you

/*
void reset(){
	object ob, room;
	int count;
	::reset();
	
	add("count",1);

	room=find_object(__DIR__"chiyouku");
	if (!objectp(room)) room=load_object(__DIR__"chiyouku");
	room->reset();
//	4*24*7, refresh every 7 days.
	if (query("count")<672+random(672)) return;
	
	set("count",0);
	
	
		
	room->set("long", @LONG
迷朦的天色到这里募地骤变，刹那间浓云翻滚，电闪雷鸣。在这人畜不至的森
罗鬼域里，赫然有十一尊大小不一的巨像。最大的巨像高达百尺，雄伟狰狞，有顶
天立地之威，睥睨天下之势，赫然便是上古传说的大神蚩尤；神像头顶赫然有一根
放射出万道金华的法杖没顶而插；其余十座塑像，分别为蛮、夷、戎、狄、黑、蛰、
邪、兽、鬼，蚩尤统领的各部落首领，塑工古朴，看起来年代久远，均向大像顶礼
膜拜。而四周则满山遍野具是森森白骨，但排列地整齐异常，而每一具白骨均头向
蚩尤巨像，俱在虔诚膜拜。
LONG);
	room->set("staff", 1);
	
}
*/

int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	object room;

	if (me->query("timer/insurance") + 259200 > time())
		return 1;

	if( userp(me))
	{
                switch(random(10))
		{
			case 0:
				message_vision("$N脚下一滑，身子在悬崖栈道上晃了晃．．\n",me);
				return notify_fail("还好，没掉下去！\n");
				break;
			case 1:
				inv = all_inventory(me);
				if(sizeof(inv)>=1)	
				{
					ob = inv[random(sizeof(inv))];
                    if (ob->query("no_drop") || ob->query("owner")
                    	|| ob->query_autoload() ) break;
					message_vision(ob->name()+"从$N身上滑了出来，落入万丈深渊．\n",me);
					destruct(ob);
				}
				return 1;
				break;
			case 2:
				message_vision("$N在悬崖栈道上前仰后合地晃着......\n",me);
				message_vision("$N连忙坐到地上，还好，终于安全了......\n",me);
				return 1;
				break;
			default:
				return 1;
				break;
		}
		return 1;
	}
	else
	return 1;
}
