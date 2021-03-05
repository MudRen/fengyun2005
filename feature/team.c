// team.c

#include <command.h>
#include <dbase.h>
#include <origin.h>

nosave object leader, *team;

string random_team_name(){
	string *lname = ({
"赵","钱","孙","李","周","吴","郑","王","冯","陈","褚","卫","蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","张",
"孔","曹","严","华","金","魏","陶","姜","戚","谢","邹","喻","柏","水","窦","章","云","苏","潘","葛","奚","范","彭","郎",
"鲁","韦","昌","马","苗","凤","花","方","傻","任","袁","柳","邓","鲍","史","唐","费","廉","岑","薛","雷","贺","倪","汤",
"藤","殷","罗","华","郝","邬","安","常","乐","呆","时","付","皮","卞","齐","康","伍","余","元","卜","顾","盈","平","黄",
"和","穆","肖","尹","姚","邵","湛","汪","祁","毛","禹","狄","米","贝","明","藏","计","伏","成","戴","谈","宋","茅","庞",
"熊","纪","舒","屈","项","祝","董","梁","樊","胡","凌","霍","虞","万","支","柯","昝","管","卢","英","万","候","司马",
"上官","欧阳","夏候","诸葛","闻人","东方","赫连","皇甫","尉迟","公羊","澹台","公治",
"宗政","濮阳","淳于","单于","太叔","申屠","公孙","仲孙","辕轩","令狐","钟离","宇文",
"长孙","幕容","司徒","师空","颛孔","端木","巫马","公西","漆雕","乐正","壤驷","公良",
"拓趾","夹谷","宰父","谷梁","楚晋","阎法","汝鄢","涂钦","段千","百里","东郭","南郭",
"呼延","归海","羊舌","微生","岳","帅","缑","亢","况","后","有","琴","梁丘","左丘","东门","西门",
	});
	return lname[random(200)] + "家帮";
}

int set_leader(object ob)
{
	if( ob==this_object() )
		error("set_leader: Cannot set this_object() as leader.\n");
	leader = ob;
}

object query_leader() { return leader; }

int follow_path(string dir)
{
// check to see if the object is able to follow
	if(this_object()->query_temp("is_unconcious") || this_object()->is_busy()) {
		return 1;
	}
	if( (origin()==ORIGIN_LOCAL) || (origin()==ORIGIN_CALL_OUT) ) {
//		this_object()->remove_all_enemy();		Holy, why ? successful go will remove enemy
		return GO_CMD->main(this_object(), dir);
	}
}

int follow_me(object ob, string dir)
{
	if( !living(this_object()) || ob==this_object() ) return 0;
	if( ob==leader
	||	(query("pursuer") && this_object()->is_killing(ob->query("id")))) {
		if( random(ob->query_skill("move")) > this_object()->query_skill("move") ) {
			remove_call_out("follow_path");
			call_out("follow_path", 1, dir);
			return 1;
		}
		return follow_path(dir);
	}
}

int add_team_member(object ob)
{
	string teamname;
	
	if( ob==this_object() ) return 0;

	if( arrayp(team) ) {
		if( member_array(ob, team)==-1 ) {
			team += ({ ob });
			ob ->set_temp("team_name",team[0]->query_temp("team_name"));
			for(int i=sizeof(team)-1; i>=0; i--)
				if(team[i])
				{
					team[i]->set_team(team);
				
				}
		} else
			return 0;
	} else {
		team = ({ this_object(), ob });
		ob->set_team(team);
		teamname = random_team_name();
		set_temp("team_name",teamname);
		ob->set_temp("team_name",teamname);
	}
	return 1;
}

int is_team_leader()
{
	return arrayp(team) && team[0]==this_object();
}

int set_team(object *t)
{
	team = t;
}

varargs int dismiss_team(object ob)
{
	int i;

	if( !arrayp(team) ) return 0;
	
	if( !ob ) {
		// if dismissed by leader, team disbands
		if( team[0]==this_object() ) {
			for(i=1; i<sizeof(team); i++)
				if(team[i]) {
					team[i]->set_team(0);
					team[i]->delete_temp("team_name");
				}
			delete_temp("team_name");	
		} else 
		// if dismissed by individual, kicked out
		{
			for(i=0; i<sizeof(team); i++)
				if(team[i] && team[i] != this_object())
				{
					team[i]->dismiss_team(this_object());
				}
			delete_temp("team_name");	// kinda redundant	
		}
		team = 0;
	} else
		{
			team -= ({ ob });
			ob->delete_temp("team_name");
		}

	return 1;
}

object *query_team()
{
	return team;
}

int 	team_member (object ob)
{
	if (!team || !sizeof(team))	return 0;
	if (member_array(ob, team) != -1)	
		return 1;
	else
		return 0;
}

//		you do the check outside :D
int	switch_team_member(object ob1, object ob2) {
	
	int i, j, k;
//	object ob;
	
	if (!team_member(ob1) || !team_member(ob2))	return 0;
		
	for (i=0;i<sizeof(team);i++){
		if ( team[i] == ob1)	j=i;
		if ( team[i] == ob2)	k=i;
	}
	
	team[j] = ob2;
	team[k] = ob1;
	
	return 1;
}