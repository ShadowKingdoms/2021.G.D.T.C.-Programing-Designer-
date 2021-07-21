using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dynamic : MonoBehaviour
{
    public float Speed;
    public float JumpPower;
    public bool isJump;

    public int Score;

    public Gun gun;
    public Vector3 dir = Vector3.right;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.RightArrow))
        {
            transform.position += Vector3.right * Speed * Time.deltaTime;
            //transform.Rotate(Vector3.up * 0);
            transform.rotation = Quaternion.Euler(Vector3.up * 0);
            dir = Vector3.right;
        }
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            transform.position += Vector3.left * Speed * Time.deltaTime;
            //transform.Rotate(Vector3.up * 180);
            transform.rotation = Quaternion.Euler(Vector3.up * 180);
            dir = Vector3.left;
        }
        
        //위아래로 움직이도록 만들기
        if (Input.GetKeyDown(KeyCode.UpArrow))
        {
            if (isJump == false)
            {
                Rigidbody2D rigidbody = this.gameObject.GetComponent<Rigidbody2D>();
                rigidbody.AddForce(Vector3.up * JumpPower);
                isJump = true;
            }
        }

        if (Input.GetKeyDown(KeyCode.Space))
            gun.Shot(dir);

        if (Input.GetKey(KeyCode.DownArrow))
            transform.position += Vector3.down * Speed * Time.deltaTime;

        if (GameManager.GetInstance().DeathZoneY > this.transform.position.y)
            Destroy(this.gameObject);
    }

    private void OnGUI()
    {
        GUI.Box(new Rect(0, 0, 100, 20), "Score:" + Score);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        isJump = false;
    }

    //private void OnCollisionExit2D(Collision2D collision)
    //{
        
    //}

    //private void OnTriggerEnter2D(Collider2D collision)
    //{
    //    if (collision.gameObject.tag == "Item")
    //    {
    //        Score++;
    //        Destroy(collision.gameObject);
    //    }
    //}
}
