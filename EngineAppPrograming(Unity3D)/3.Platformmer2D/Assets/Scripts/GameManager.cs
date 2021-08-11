using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public string strVer = "Ver.0.00.00";
    public Text textVer;

    public CameraTracker cameraTracker;

    public Responner responnerPlayer;
    public Responner responnerOpossum;
    public Responner responnerEagle;

    public float DeathZoneY = -1;

    public ItemIventory itemIventory;

    public MobileController mobileController;

    public void EventEatItem(Item.ITEM_KIND item_kind)
    {
        itemIventory.SetIventory(item_kind);
    }

    public void EventItemUse(Item.ITEM_KIND item_kind, GameObject obj)
    {
        Item.Use(item_kind, obj);
        itemIventory.RemoveIventory(item_kind);
    }

    public void EventItemUsePlayer(Item.ITEM_KIND item_kind)
    {
        if (responnerPlayer.objPlayer)
        {
            Item.Use(item_kind, responnerPlayer.objPlayer);
            itemIventory.RemoveIventory(item_kind);
        }
    }

    public void DeathZoneGizmo()
    {
        Vector3 vStartPos = new Vector3(-9999999999, DeathZoneY, 0);
        Vector3 vEndPos = new Vector3(9999999999, DeathZoneY, 0);
        Gizmos.color = Color.red;
        Gizmos.DrawLine(vStartPos, vEndPos);
    }

    //싱글톤: 게임관리자를 어떤객체든 쉽게 접근하게 만들수있다.
    static GameManager instance;
    public static GameManager GetInstance()
    {
        return instance;
    }

    // Start is called before the first frame update
    void Start()
    {
        instance = this;
        textVer.text = strVer;
        SetGUIScene(curGUIState);
    }

    // Update is called once per frame
    void Update()
    {
        if(cameraTracker.objTarget == null)
            cameraTracker.objTarget = responnerPlayer.objPlayer;

        if (mobileController.dynamic == null && responnerPlayer.objPlayer)
            mobileController.dynamic = responnerPlayer.objPlayer.GetComponent<Dynamic>();

        UpdateEagleRetrunPointCheck();
        UpdateState();
    }

    private void UpdateEagleRetrunPointCheck()
    {
        if(responnerEagle.objPlayer)
        {
            Eagle eagle = responnerEagle.objPlayer.GetComponent<Eagle>();
            if(eagle.objResponPoint ==null)
                eagle.objResponPoint = responnerEagle.gameObject;
        }
    }

    private void OnDrawGizmos()
    {
        DeathZoneGizmo();
    }

    public void EventChageScene(int stateNumber)
    {
        SetGUIScene((E_GUI_STATE)stateNumber);
    }

    public List<GameObject> listGUIScenes;
    public enum E_GUI_STATE { TITLE, THEEND, GAMEOVER, PLAY }
    public E_GUI_STATE curGUIState;

    public GameObject objPopupLayer;

    public Text textPlayerName;
    public Text textPlayerLv;
    public GUIStatusBar guiPlayerHp;
    public GUIStatusBar guiPlayerMp;
    public GUIStatusBar guiPlayerExp;

    public GUIIemIventory guiItemIventory;

    public void EventItemIventory()
    {
        if (objPopupLayer.activeSelf)
        {
            objPopupLayer.SetActive(false);
        }
        else
        {
            objPopupLayer.SetActive(true);
        }
    }

    public void UpdatePlayerStatus()
    {
        if(responnerPlayer.objPlayer)
        {
            Player player = responnerPlayer.objPlayer.GetComponent<Player>();

            textPlayerLv.text = string.Format("Lv.{0}",player.nLv);
            textPlayerName.text = responnerPlayer.objPlayer.name;
            guiPlayerHp.SetValue(player.playerStatus.nHP, player.nMaxHP);
            guiPlayerMp.SetValue(player.playerStatus.nMP, player.nMaxMP);
            guiPlayerExp.SetValue(player.nExp, player.nMaxExp);
        }
    }

    public void ShowScenec(E_GUI_STATE state)
    {
        for (int i = 0; i < listGUIScenes.Count; i++)
        {
            if ((E_GUI_STATE)i == state)
                listGUIScenes[i].SetActive(true);
            else
                listGUIScenes[i].SetActive(false);
        }
    }
    public void SetGUIScene(E_GUI_STATE state)
    {
        switch (state)
        {
            case E_GUI_STATE.TITLE:
                //단, 타이머관련된 기능과 애니메이션관련 기능이 모두 정지된다.
                //deltaTime * timeScale
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.THEEND:
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.GAMEOVER:
                Time.timeScale = 0;
                break;
            case E_GUI_STATE.PLAY:
                Time.timeScale = 1;
                break;
        }
        ShowScenec(state);
        curGUIState = state;
    }
    public void UpdateState()
    {
        switch (curGUIState)
        {
            case E_GUI_STATE.TITLE:
                break;
            case E_GUI_STATE.THEEND:
                break;
            case E_GUI_STATE.GAMEOVER:
                break;
            case E_GUI_STATE.PLAY:
                UpdatePlayerStatus();

                if(Input.GetKeyDown(KeyCode.I))
                {
                    EventItemIventory();
                }

                if(objPopupLayer.activeSelf)
                {
                   if(itemIventory.listItems.Count != guiItemIventory.listItemButtens.Count)
                    {
                        guiItemIventory.ClearIventory();
                        guiItemIventory.SetIventory(itemIventory);
                    }
                }

                break;
        }
    }

}