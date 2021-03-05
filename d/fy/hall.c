#include <ansi.h>
inherit ROOM;
int done_jiqi(object me);

//	void load_item(object me);
int	do_update(object me);
void	reset_player(object ob);

void create()
{
    set("short", HIY"风云天骄门"NOR);
    set("long", @LONG
这是一座古老而神圣的大理石门，大约建于百年前。门上斑斑点点，风化不堪。
传说中是玉皇大帝临凡嘉奖天下儿女英雄的地方，凡是被嘉奖的英雄都成为不死之
身，他们的事迹千万年为世人传颂。微风习习拂面，如果在这里吐纳（[37mｔｕｎａ[32m）
天地之灵气，必将对你的武学修养有极大提高。由此向上，便是天下英雄向往的争
夺武林第一人的所在——[1;31m天下英雄榜[0;32m。
LONG
    );
    set("exits", ([ 
	"south" : __DIR__"nwind4",
	"north" : __DIR__"jinshuihe",
	"up" : __DIR__"mirrorgallery",
      ]));
	set("no_fight",1);
	set("no_fly",1);
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",240);
    set("coor/z",0);
    set("map","fynorth");
    setup();

}

void init(){
	add_action("do_jiqi","tuna");
}

int do_jiqi(){
        object me;
        mapping buff_list, condition;
  		string *a;
  		int i;
  	      
        me = this_player();
		if (me->is_busy())	
			return notify_fail("你现在正忙。\n");
	
		"/cmds/std/remove.c"->main(me,"all");
    	
    	condition = me->query_all_condition();
    	buff_list = me->query_temp("buff");
    	if (sizeof(condition))
    		return notify_fail("你身有异状，无法静心吐纳。\n");


		if (sizeof(buff_list)) {
			a = keys(buff_list);
			for (i=0;i<sizeof(buff_list);i++) {
				if (buff_list[a[i]])
					return notify_fail("你身有异状，无法静心吐纳。\n");
    		}
    	}	
    	
    	if (me->query_temp("jiqi/in_tuna"))
    		return notify_fail("你正在吐纳中。\n");
    			
	message_vision(HIG"\n凉风习习，$N双手虚抱，伫立在风云天骄门，缓缓吐纳丹田之气。\n"NOR,me);
	me->set_temp("jiqi/in_tuna",1);
	me->add_temp("jiqi/num",1);
	me->perform_busy(3);
	call_out("done_jiqi",4, me);
//	done_jiqi(me);
	return 1;
}

int done_jiqi(object me) {
	
	string msg;
	
	if (!me || me->is_ghost() || environment(me)!= this_object())
		return 1;
		
	if (me->query_temp("jiqi/num")>=3) {
		msg = HIR"
一周天后，你只觉内内外外的真气激荡，全身脉络之中，有如一条条
水银在到处流转，舒适无比。恰如水火相济，龙虎交会，身上数十处
玄关一一冲破，竟是大功告成了。\n\n"NOR;
		me->delete_temp("jiqi");
		do_update(me);
		if (me->query("eff_kee")>me->query("max_kee")) me->set("eff_kee",me->query("max_kee"));
		if (me->query("eff_gin")>me->query("max_gin")) me->set("eff_gin",me->query("max_gin"));
		if (me->query("eff_sen")>me->query("max_sen")) me->set("eff_sen",me->query("eff_sen"));
		if (me->query("kee")>me->query("eff_kee")) me->set("kee",me->query("eff_kee"));
		if (me->query("gin")>me->query("eff_gin")) me->set("gin",me->query("eff_gin"));
		if (me->query("sen")>me->query("eff_sen")) me->set("sen",me->query("eff_sen"));
	} else {
		msg = YEL"
一周天后，你只觉内内外外的真气激荡，全身脉络之中，有如一条条
水银在到处流转，舒适无比。\n\n"NOR;
		me->delete_temp("jiqi/in_tuna");
	}
	tell_object(me,msg);
	me->stop_busy();
	return 1;
}


int	do_update(object me){
	
        if (!objectp(me) 
        	|| me->is_ghost())
        	return 1;
        
// 重新计算精气神值，这个与logind中的计算相同。	

// 修改呼叫函式统一处理 :: annie
		"/cmds/std/unwield.c"->main(me,"all");
		"/cmds/std/remove.c"->main(me,"all");
        "/feature/nada.c"->reset_player_status(me);
        me->save();	
        return 1;

}



