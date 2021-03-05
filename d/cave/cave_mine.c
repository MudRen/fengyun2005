/*  小土洞 
 ｜ 
西北角 — 西北门 — 天西北道 — 天外天 — 天东北道 — 东北门 — 东北角 
｜ ｜        ｜ 
北天西门       	  火牢           北天东门 
｜ 	  		 ｜ 
    ｜		    小仓房	  土牢				     ｜	
    ｜		      ｜	   ｜  				     ｜	
北天西路  大食堂       天北中门 	 北天东路 
｜｜   ｜	   ｜ 
天中道西—中道西门—西中道        天庭 — 东中道       金牢 — 天中道东 
｜ ｜  ｜         ｜＼ 
南天西路紫电青霜阁    天南中门            南天东路木牢 
  ｜ ｜         ｜ 
水牢   天南中路          南天东门 
 ｜         ｜ 
西南角 — 天西南道 — 西南门 —青石中路 — 东南门 — 天东南道 — 东南角
			
*/

#include <ansi.h>
inherit ROOM;

int valid_leave(object obj, string dir){
		object ob, *inv;
		int i,n;	
		string block_dir, *blocker;
		string *npc = ({
			"亢金龙","柳土獐","星日马","张月鹿",
			"翼水蛇","井木犴","轸火蚓","斗木獬",
			"牛金羊","虚日鼠","危月燕","室火猪",
			"壁水獐","角木蛟","亢金龙","氐土貉","房月狐"
		});
		string *npc_e = ({
			"a", "b", "c", "d",
			"e", "f", "g", "h",
			"i", "j", "k", "l",
			 "m", "n", "o", "p","q"
			});
		switch (query("short")) {
				case	"南天西路": blocker = ({ "a", "b", "c", "d" }); 
								block_dir = "north"; 
								break;
				case	"天中道西": blocker = ({ "a", "b", "c", "d" }); block_dir = "north"; break;
				case	"北天西路": blocker = ({ "a", "b", "c", "d" }); block_dir = "north"; break;	
				case	"北天西门": blocker = ({ "a", "b", "c", "d" }); block_dir = "south"; break;
				case	"西北门": 	blocker = ({ "e", "f", "g", "h" }); block_dir = "west"; break;
				case	"天西北道": blocker = ({ "e", "f", "g", "h"}); block_dir = "east"; break;
				case	"天外天": 	blocker = ({ "e", "f", "g", "h"}); block_dir = "east"; break;				
				case	"天东北道": blocker = ({ "e", "f", "g", "h"}); block_dir = "east"; break;
				case	"东北门": 	blocker = ({ "e", "f", "g", "h" }); block_dir = "west"; break;
				case	"北天东门": blocker = ({ "i", "j", "k", "l" }); block_dir = "south"; break;		
				case	"北天东路": blocker = ({ "i", "j", "k", "l" }); block_dir = "north"; break;	
				case	"天中道东": blocker = ({ "i", "j", "k", "l" }); block_dir = "south"; break;	
				case	"南天东路": blocker = ({ "i", "j", "k", "l" }); block_dir = "south"; break;	
				case	"南天东路": blocker = ({}); block_dir = ""; break;		// 瘴气	
				case	"天东南道": blocker = ({ "m", "n", "o", "p","q" }); block_dir = "west"; break;
				case	"东南门": 	blocker = ({ "m", "n", "o", "p","q" }); block_dir = "west"; break;
				case	"青石中路": blocker = ({ "m", "n", "o", "p","q" }); block_dir = "west"; break;
				case	"西南门": 	blocker = ({ "m", "n", "o", "p","q" }); block_dir = "east"; break;
				case	"天西南道": blocker = ({ "m", "n", "o", "p","q" }); block_dir = "west"; break;
				}	
		
//		CHANNEL_D->do_sys_channel("sys", sprintf("location is %s, blocker is %O, time is %d\n",query("short"),blocker, time()-query("cave_mine")));
		
		if(dir == block_dir && sizeof(blocker)>0 ){
			inv = all_inventory();
			if (inv && sizeof(inv))
				for (i=0;i<sizeof(inv);i++) {
					if (inv[i]->query("cave_killer")) {
						ob = inv[i];
						break;
					}
				}
							
			if (ob)	
				return notify_fail(ob->name()+"闪身挡住了你的路。\n");
			else if (query("cave_mine")+ 20 < time() && random(10)>7) {
				seteuid(getuid());
				
				if ( (n = member_array(obj->query("quest/quest"), npc)) != -1 //	killer quest
					&& member_array(npc_e[n], blocker)!= -1)				  // And that killer is in current area list
				{
					ob = new(__DIR__"npc/killer_"+npc_e[n]);			// We generate this killer immediately	
					ob->set("combat_exp", obj->query("combat_exp"));		// Killer skill/pfm sucks.. so same exp 
					"/feature/nada"->reset_npc(ob);
					ob->full_me();
					ob->set("title",HIC"青龙杀手头目"NOR);
				} else
				{			
					ob = new(__DIR__"npc/killer_"+ blocker[random(sizeof(blocker))]);
				}
			
				ob->move(this_object());
				message_vision(HIB"路边黑影一闪!$N喝道，什么人敢私闯青龙会，拿命来！\n"NOR, ob);	
				ob->kill_ob(obj);
				return notify_fail("");
			}
		}	
		return ::valid_leave(obj, dir);
}
