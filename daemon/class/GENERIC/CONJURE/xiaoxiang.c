// 琴 思路 by Sinny/Silencer@fy4.
// 清心普善曲： 
// 十面埋伏曲：
// 百鸟朝凤曲： 
// 碧海潮生曲:  
// 潇湘水云曲：
// 广陵散

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	string msg,area;
	object weapon,room;
	object * stuff;
	int skill, your_exp, my_exp, damage, i, qin;

	if (me->is_ghost())
		return notify_fail("你尚是鬼魂，还是想法先回阳间吧。\n");
	
	stuff = all_inventory(me);
	qin=0;
	for (i=0;i<sizeof(stuff) ;i++){
		if(qin < stuff[i]->query("timbre")){
		  qin = stuff[i]->query("timbre");
		}
	}  
	if(!qin && userp(me)) return notify_fail("你好像忘记带琴了。\n");
	
	skill = me->query_skill("music",1);		
	if (!skill)
		return notify_fail("你于音律一窍不通，瞎拨了几下，顿觉索然无味。\n");
		if (me->query("annie/music_choose") != 2)
		return notify_fail("这曲子你似乎没学会诶。\n");

	if (skill < 150)
		return notify_fail("你发现此谱过于高深，至少需要150级的琴道才能演奏。\n");

	if (me->is_fighting())
	        return notify_fail("战斗中不能弹奏『潇湘水云曲』\n");
    
  	if (stringp(me->query_temp("no_move")))
		return notify_fail(me->query_temp("no_move"));	
		    
	room = environment(me);
	area = room->query("outdoors");
	if (!area) 
		return notify_fail(CYN"你信手拨弹了几下，琴声肃杀凄凉，令人潸然泪下。\n你不在室外，仙鹤找不到你诶。\n"NOR);	
  
  	if( me->query("atman") < 500 )
		return notify_fail("弹奏『潇湘水云曲』需要５００点灵力！\n");
	if (userp(me)) me->add("atman",-500);
               
	message_vision(CYN"
$N远望碧空，但见云水掩映，不由细心静坐，低弹轻拂，但闻雨声萧萧，
尽是凄凉肃杀之象，细雨绵绵，若有若无，万籁俱寂。     

\n"NOR,me);
	call_out("move_him",1+random(4),me, area);
	return 1;
}



int move_him(object me, string area)
{

	object room;
	string room_name;
	
	// Put checks here to ensure legitimacy
	
	if (!me || me->is_ghost())	return 1;
	
	if (me->is_fighting()|| me->is_busy())	return 1;		
	if (environment(me)->query("no_fly"))	return 1;
	if (stringp(me->query_temp("no_move")))	return 1;
	room = environment(me);
	area = room->query("outdoors");
	if (!area) return 1;
				
	message_vision(CYN"一曲方罢，空朦云雨之间清鸣数声，一只玄鹤几个回旋缓缓落在$N的身旁。\n\n"NOR,me);
	message("vision",CYN""+me->name()+"骑上鹤背，拍了拍鹤颈腾空而去。。。。\n"NOR,environment(me),me);
	tell_object(me,"你骑上鹤背，拍了拍鹤颈，玄鹤腾空而起。\n");
        
        tell_object(me, WHT"
        
        
        		云间
        
    耳畔风声呼呼，眼前白云片片，俯瞰，风云城依稀可见。。。。。。
    
    
    
    	\n"NOR);
	
	if (area == "tieflag" && file_name(environment(me))[0..11]!="/d/changchun")
		area = "nada";
	
	switch (area) {
		case "tieflag":   room_name = AREA_BAIYUN"jietiandian";
				  break;	
		case "baiyun":	  room_name = AREA_FY"fysquare";
				  break;	
		default:	  	  room_name = AREA_CHANGCHUN"moonding";
	}
	seteuid(ROOT_UID);
        room = find_object(room_name);
	if (!room) room = load_object(room_name);
	seteuid(geteuid());
	
	message("vision",CYN"\n鹤唳声声，"+me->name()+"御玄鹤从天而降。\n"NOR,room,me);
	tell_object(me,"玄鹤慢慢地降到地面，你走下鹤背。\n\n");
	TASK_D->flying_risk(me);
	me->move(room_name);
	message_vision(CYN"玄鹤绕着$N的头顶眷恋的盘旋了几圈，一声长鸣，展翅飞入云天之中。\n"NOR,me);
	return 1;
}
		